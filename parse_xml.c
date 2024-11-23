#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void printBookTitles(const char *filename) {
    // Parse the XML file and build a document tree
    xmlDoc *doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        printf("Error: Could not parse the file %s\n", filename);
        return;
    }

    // Get the root element node
    xmlNode *root = xmlDocGetRootElement(doc);
    for (xmlNode *curNode = root->children; curNode; curNode = curNode->next) {
        // Check for book elements
        if (curNode->type == XML_ELEMENT_NODE && xmlStrcmp(curNode->name, (const xmlChar *)"book") == 0) {
            for (xmlNode *bookChild = curNode->children; bookChild; bookChild = bookChild->next) {
                if (bookChild->type == XML_ELEMENT_NODE && xmlStrcmp(bookChild->name, (const xmlChar *)"title") == 0) {
                    printf("Book Title: %s\n", xmlNodeGetContent(bookChild));
                }
            }
        }
    }

    // Free the document
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <xml-file>\n", argv[0]);
        return 1;
    }

    printBookTitles(argv[1]);
    return 0;
}

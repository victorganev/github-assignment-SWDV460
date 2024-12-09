all: parse_xml
parse_xml: parse_xml.c
	gcc -o parse_xml parse_xml.c -I/usr/include/libxml2 -lxml2
clean:
	rm -f parse_xml

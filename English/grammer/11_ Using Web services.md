# 11: Using Web services
###### tags: `python learn`

There are two common formats that we use when exchanging data across the web. The “eXtensible Markup Language” or XML has been in use for a very long time and is best
suited for exchanging document-style data. When programs just want to exchange dictionaries, lists, or other internal information with each other, they use JavaScript Object Notation or JSON (see www.json.org). We will look at both formats

## Parsing XML
```python=
import xml.etree.ElementTree as ET

data = '''
<person>
<name>Chuck</name>
<phone type="intl">
+1 734 303 4456
</phone>
<email hide="yes"/>
</person>'''


tree = ET.fromstring(data)
print('Name:', tree.find('name').text)
print('Attr:', tree.find('email').get('hide'))
```

Calling `fromstring` converts the string representation of the XML into a “tree” of XML nodes. When the XML is in a tree, we have a series of methods we can call to extract
portions of data from the XML.

The `find` function searches through the XML tree and retrieves a node that matches the specified tag.

## Looping through nodes
Often the XML has multiple nodes and we need to write a loop to process all of the nodes. In the following program, we loop through all of the `user` nodes
```python=
import xml.etree.ElementTree as ET

input = '''
<stuff>
	<users>
		<user x="2">
		<id>001</id>
		<name>Chuck</name>
		</user>
		<user x="7">
		<id>009</id>
		<name>Brent</name>
		</user>
	</users>
</stuff>'''

stuff = ET.fromstring(input)
lst = stuff.findall('users/user')
print('User count:', len(lst))

for item in lst:
    print('Name', item.find('name').text)
    print('Id', item.find('id').text)
    print('Attribute', item.get('x'))
```

## Parsing JSON
We construct our JSON by nesting dictionaries (objects) and lists as needed. In this example, we represent a list of users where each user is a set of key-value pairs (i.e., a dictionary). So we have a list of dictionaries.
```python=
import json

data = '''
[
	{ 	"id" : "001",
		"x" : "2",
		"name" : "Chuck"
	} ,
	{
		"id" : "009",
		"x" : "7",
		"name" : "Chuck"
	}
]
'''

info = json.loads(data)
print('User count:', len(info))
for item in info:
    print('Name', item['name'])
    print('Id', item['id'])
    print('Attribute', item['x'])
```
## Application Programming Interfaces
The next step is to begin to define and document “contracts” between applications using these techniques. The general name for these application-to-application contracts is Application Program Interfaces or APIs.

When we begin to build our programs where the functionality of our program includes access to services provided by other programs, we call the approach a Service Oriented Architecture or SOA. A SOA approach is one where our overall application makes use of the services of other applications. A non-SOA approach is where the application is a single standalone application which contains all of the code necessary to  implement the application.

![](https://i.imgur.com/OBWQanR.png)

## Security and API usage
Sometimes once you get your API key, you simply include the key as part of POST data or perhaps as a parameter on the URL when calling the API.

Other times, the vendor wants increased assurance of the source of the requests and so they add expect you to send cryptographically signed messages using shared keys and secrets. A very common technology that is used to sign requests over the Internet is called OAuth. You can read more about the OAuth protocol at www.oauth.net.


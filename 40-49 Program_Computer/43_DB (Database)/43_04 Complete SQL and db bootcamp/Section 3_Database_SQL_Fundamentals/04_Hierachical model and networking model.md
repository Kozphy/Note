#database 

## Hierachical model like Tree structure
Parent have multiple children but each child only have one parent.
![](Pasted%20image%2020240508191643.png)

### It also like xml.
```xml
<Author>
	<Mo>
		<Name>Mo Binni</Name>
		<Country>Canada</Country>
		<Book1>
			<Released>01/01/1990</Released>
		</Book1>
		<Book2>
			<Released>01/01/1993</Released>
		</Book2>
	</Mo>
	<Andrei>
		<Name>Andrei Neagoie</Name>
		<Country>Canada</Country>
		<Book1>
			<Released>01/01/1990</Released>
		</Book1>
		<Book2>
			<Released>01/01/1993</Released>
		</Book2>
	</Andrei>
</Author>
```

## Networking model
Networking model expanded on the hierarchical model, allowing `many to many relationships`.

We can now see that child entities can have multiple parents, and parents can have multiple children
![](Pasted%20image%2020240509143544.png)

```xml
<Author>
	<Mo>
		<Name>Mo Binni</Name>
		<Country>Canada</Country>
		<Book1 author="Andrei" relation="co-author"/>
		<Book2>
			<Released>01/01/1990</Released>
		</Book2>
	</Mo>
	<Andrei>
		<Name>Andrei Neagoie</Name>
		<Country>Canada</Country>
		<Book1>
			<Released>01/01/1990</Released>	
		</Book1>
		<Book2>
			<Released>01/01/1993</Released>
		</Book2>
	</Andrei>
</Author>
```
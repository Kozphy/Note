[source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-ip-addresses)

# IP addresses
Each server or client on a TCP/IP internet is identified by a numeric IP (Internet Protocol) address. The two types of IP address are the `IPv4` (IP version 4) address and the `IPv6` (IP version 6) address.

# IPV6 addresses
```
IP address in hexadecimal notation :   '000100220333444400000000abc0def0'x
Halfword 0:  0001 hexadecimal
Halfword 1:  0022 hexadecimal
Halfword 2:  0333 hexadecimal
Halfword 3:  4444 hexadecimal
Halfword 4:  0000 hexadecimal
Halfword 5:  0000 hexadecimal
Halfword 6:  abc0 hexadecimal
Halfword 7:  def0 hexadecimal
IP address in colon hexadecimal notation: 1:22:333:4444::abc0:def0

IP address in hexadecimal notation :   '00000000000000000000ffff01020304'x
Halfword 0:  0000 hexadecimal
Halfword 1:  0000 hexadecimal
Halfword 2:  0000 hexadecimal
Halfword 3:  0000 hexadecimal
Halfword 4:  0000 hexadecimal
Halfword 5:  ffff hexadecimal
Halfword 6:  0102 hexadecimal
Halfword 7:  0304 hexadecimal
IP address in colon hexadecimal notation: ::ffff:1.2.3.4 or ::ffff:0102:0304
```

IPv6 addresses are 128-bit addresses, usually expressed in `hexadecimal` notation:

The address consists of eight halfword fields. `Zeros are treated in the following ways` in the address output:
- If a `field contains leading zeros`, they are ignored; for example, 0001 is represented as 1
- If one or more consecutive fields in the address contain the value `0000`, these fields are expressed using the notation `::` For example, `000000000000ffff is represented as ::ffff`

The `:: substitution is used once only in an address`, to avoid confusion in calculating how many fields were substituted.

# IPV4
IPv4 addresses are 32-bit addresses, usually expressed in dotted `decimal` notation:
```
IP address in hexadecimal notation :   '817EB263'x
Byte 0:  81 hexadecimal = 129 decimal
Byte 1:  7E hexadecimal = 126 decimal
Byte 2:  B2 hexadecimal = 178 decimal
Byte 3:  63 hexadecimal =  99 decimal
IP address in dotted decimal notation: 129.126.178.99
```

In this example, `129.126` specifies the `network` and `178.99` specifies the `host` on that network.
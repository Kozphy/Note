# [source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-port-numbers)

> Last updated: 2022/10/07

## Port numbers

In a server, more than one user process can use TCP at the same time. `To identify the data associated with each process, port numbers are used`. Port numbers are 16-bit, and `numbers up to 65535` are possible, although in practice only a small subset of these numbers is commonly used.

When a `client` process `first contacts a server process`, it might use a `well-known port number to initiate communication`.

Well-known port numbers are assigned to particular services throughout the Internet, by IANA, the Internet Assigned Numbers Authority. The `well-known port numbers are in the range 0 through 1023`. Some examples are shown in Table 1:
![well_known_port_table](./well_known_port.drawio.svg)

`Well-known ports are used only to establish communication between client and server processes`.

After that, the server allocates an ephemeral port number for subsequent use. `Ephemeral port numbers are unique port numbers, which are assigned dynamically when processes start communicating. They are released when communication is complete`.

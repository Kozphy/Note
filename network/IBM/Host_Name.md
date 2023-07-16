# [source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-host-names)

## Host names

A host, or website, on the Internet is identified by a `host name`, such as `www.example.com`.

`Host` names are sometimes called `domain names`. Host names are mapped to `IP addresses`, but a `host name` and an `IP address` do not have a `one-to-one relationship`.

A `host name` is used when a web client makes an HTTP `request` to a host. The user making the request can specify the IP address of the server rather than the host name, but that is now `unusual` on the Internet. `Host names` are more convenient for users than `numeric IP addresses`.

More importantly in modern HTTP implementations, the use of host names in HTTP requests has these consequences:

- `Services in the name of one host` can be provided by `many servers`, which have `different IP addresses`.
- `One server, with one IP address`, can provide services in the name of many hosts. This usage is known as `virtual hosting`. [Virtual hosting](./Virtual_hosting.md) explains this process.

`Host names` are mapped to `IP addresses by a server known as a DNS server` or `domain name server`. In a large network, many `DNS servers collaborate to provide the mapping between host names and IP addresses`.

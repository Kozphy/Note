# [source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-virtual-hosting#dfhtl_virthost)

# Virtual hosting
HTTP includes the concept of virtual hosting, where `a single HTTP server can represent multiple hosts at the same IP address.` 

You can use virtual hosting in web support by `setting up URIMAP resources`.

`A DNS server` can allocate several `different host names to the same IP address.` When an HTTP client makes a request to a particular host, it uses the DNS server to locate the IP address corresponding to that host name, and sends the request to that IP address.

`In HTTP/1.0 the host name` does not appear in the `HTTP message`; it is lost after the IP address has been resolved. If more than one set of resources is held on the server represented by the IP address, the server has difficulty distinguishing which resources belong to which host.

However, `HTTP/1.1 requests` provide the `host name` in the request, usually in a `Host header`. The presence of the host name in the message enables the HTTP server to direct requests containing different host names to the appropriate resources for each host. This feature of HTTP is known as `virtual hosting`. CICS® web support provides support for virtual hosting through the use of URIMAP resources.

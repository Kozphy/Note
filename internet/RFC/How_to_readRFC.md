# [source](https://www.ietf.org/blog/how-read-rfc/)
# How to read RFC
> Last updated: 2022/10/7
## Where to start?
you can use following tool to search or read RFC:
- [tools.ietf.org](https://authors.ietf.org/)
- [rfc.fyi](https://rfc.fyi/): put together to allow searching RFCs by their titles and keywords, and exploration by tags.
- [rfc editor](https://www.rfc-editor.org/rse/format-faq/): much more pleasing presentation and the option for customisation
- [greenbytes](https://greenbytes.de/tech/webdav/): keeps a list of WebDAV-related RFCs
- [HTTP working Group](https://httpwg.org/specs/): maintains a selection of those related to HTTP.

## What kind of RFC is it?
![kind of rfc](./kind_of_rfc.drawio.svg)

At the top left, this one says “Internet Engineering Task Force (IETF)”. That indicates that this is a product of the IETF.

Only the IETF stream indicates that the entire IETF has reviewed and has declared consensus on a protocol’s specification.

Under that is the `“Request for Comments” number`. `If it says “Internet-Draft”` instead, it’s not an RFC; it’s just a `proposal`, and `anyone can write one`. Just because something is an Internet-Draft doesn’t mean it’ll ever be adopted by the IETF.

`Category` is one of “Standards Track”, “Informational”, “Experimental”, or “Best Current Practice”. The distinctions between these are sometimes fuzzy, but if it’s produced by the IETF (see above), it’s had a reasonable amount of review. However, `note that Informational and Experimental are not standards`, even if there’s IETF consensus to publish.

## Is it current?
RFCs are an archival series of documents; they can’t change.

As a result, `it’s important to know that you’re looking at the right document`. The header contains a couple of bits of metadata that help here:
- **Obsoletes**: `lists the RFCs that this document completely replaces`; i.e., you should be using this document, not that one. Note that an old version of a protocol isn’t necessarily obsoleted when a newer one comes out; for example, HTTP/2 doesn’t obsolete HTTP/1.1, because it’s still legitimate (and necessary) to implement the older protocol. However, RFC7230 did obsolete RFC2616, because it’s the reference for that protocol.
- **Updates**: lists the RFCs that this document makes substantive changes to; in other words, `if you’re reading that other document, you should probably read this one too`.


Unfortunately, the `ASCII text RFCs (e.g., at the RFC Editor site) don’t tell you what documents update or obsolete the document you’re currently looking at`.

This is why most people use the RFC repository at tools.ietf.org, which puts this information in a [banner like this](https://www.rfc-editor.org/rfc/rfc2616):
![rfc_current_banner](./rfc_current_banner.drawio.svg)

Even the most current RFC often has issues. `In the tools banner, you’ll also see a warning on the right that “Errata Exist” along with a link to Errata above it`.

**Errata** are corrections and clarifications to the document `that aren’t worthy of publishing a new RFC`. Sometimes they can have a substantial impact on how the RFC is implemented (for example, if a bug in the spec led to a significant misinterpretation), so they’re worth going through.

## Understanding context
`It’s more common than you might think for a developer to look at a statement in an RFC, implement what they see, and do the opposite of what the authors intended.`

This is because `it’s extremely difficult to write a specification in a manner that can’t be misinterpreted when reading it selectively` (as is the case with any holy text).

As a result, it’s necessary to read not only the directly relevant text but also (at a minimum) anything that it references, whether that’s in the same spec or a different one. In a pinch, `reading any potentially related sections will help immensely, if you can’t read the whole document`.

For example, `HTTP message headers` are [defined](https://httpwg.org/specs/rfc7230.html#http.message) to `be separated by CRLF`, but if you skip down [here](https://httpwg.org/specs/rfc7230.html#message.robustness), `you’ll see that “a recipient MAY recognize a single LF as a line terminator and ignore any preceding CR.”` Obvious, right?

It’s also important to `keep in mind` that `many protocols set up` [IANA registries](https://www.iana.org/protocols) to `manage their extension points`; these, not the specifications, are the [sources of truth](https://en.wikipedia.org/wiki/Single_source_of_truth). For example, the canonical list of HTTP methods is in [this registry](https://www.iana.org/assignments/http-methods/http-methods.xhtml), not any of the HTTP specifications.

## Interpreting requirements
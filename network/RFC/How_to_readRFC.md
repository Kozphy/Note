# How to read RFC

## [source](https://www.ietf.org/blog/how-read-rfc/)

> Last updated: 2022/10/8

- [How to read RFC](#how-to-read-rfc)
  - [source](#source)
  - [Where to start?](#where-to-start)
  - [What kind of RFC is it?](#what-kind-of-rfc-is-it)
  - [Is it current?](#is-it-current)
  - [Understanding context](#understanding-context)
  - [Interpreting requirements](#interpreting-requirements)
  - [SHOULD](#should)

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

Almost all RFCs have boilerplate that looks something like this near the top:
![boilerplate](./boilerplate.drawio.svg)

These [RFC2119](./RFC2119.md) keywords help define interoperability, but they also sometimes confuse developers. It’s very common to see a specification say something like:

```text
The Foo message MUST NOT contain a Bar header
```

This requirement is placed upon a protocol artefact, the” Foo message”. If you’re sending one, it’s `pretty clear it needs to not contain a Bar header`; if you include one, it won’t be a conformant message.

However, the behaviour of the recipient is much less clear; `if you see a Foo message with a Bar header, what do you do?`

Some developers will `reject a message that contains it`, even though the `specification says nothing about doing so`. Others will `still process` the message, `but strip the Bar header`, or `ignore it` – `even` when the `spec explicitly says that all headers need to be processed`.

All of these things can – unintentionally – `cause interoperability` issues. The `correct thing` to do is to `follow normal processing for the header unless there’s a specific requirement to the contrary`.

That’s because in general, specifications are written so that behaviours are overtly specified; in other words, `everything that is not explicitly disallowed is allowed`. Therefore, reading too much into specifications can unintentionally cause harm, since you’ll be introducing new behaviours that others will have to work around.

`In an ideal world`, the specification would be `defined in terms of the behaviours of those who handle the message`, like this:

```text
Sender of the Foo messages MUST NOT include a Bar header. Recipients
of a Foo message that includes a Bar header MUST ignore the Bar header,
but MUST NOT remove it.
```

`Absent that`, it’s `best to look for more general advice about error handling` elsewhere in the specification (e.g., HTTP’s [Conformance and Error Handling](https://httpwg.org/specs/rfc7230.html#conformance) section).

Also, `keep in mind` the `target of requirements`; most specifications have a highly developed `set of terms` that they use to `distinguish between different roles in the protocol`.

For example, HTTP has `proxies`, which are a `kind of intermediary`, which implement both a client and a server (but not a User-Agent or an origin server); they need to pay attention to `requirements targeted at all of those roles`.

Likewise, HTTP distinguishes between “generating” a message and merely “forwarding” it in some requirements, depending on the specific situation. Paying attention to this kind of specific terminology can save you a lot of guesswork.

## SHOULD

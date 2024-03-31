#dataScience 

## Server Side Render (SSR)
### Process
- When a user requests a page, the server processes the request.
	- The server generates the HTML content for the requested page by executing server-side code (e.g., using a backend framework like Express.js or Django).
	- The fully-rendered HTML is sent to the client.
	- The client displays the HTML content directly.
### **Advantages**
- **Faster Initial Load Times**: Since the server provides pre-rendered HTML, the initial page load is faster.
- **SEO Optimization**: Search engines can easily index the content because it’s available in the HTML.
### - **Use Cases**
`SSR` is suitable for applications that require high performance, SEO optimization, and scalability.

## CSR (Client side render)
###  **Process**
- The server sends a minimal HTML page (often called a “shell” or “skeleton”) to the client.
- The client-side JavaScript framework (e.g., React, Vue, or Angular) takes over.
- The framework fetches data from APIs and dynamically renders the content on the client side. 
### **Advantages**
- **Interactivity**: Allows for dynamic and interactive web apps (e.g., real-time updates, single-page applications).
- **Faster Subsequent Page Loads**: Once the initial page is loaded, subsequent navigation within the app doesn’t require full page reloads.
###  **Use Cases**
`CSR` is better for applications that require a lot of interactivity and faster development time.
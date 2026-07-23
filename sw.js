// A simple Service Worker to satisfy Chrome's PWA install requirements
self.addEventListener('install', (event) => {
    self.skipWaiting();
});

self.addEventListener('activate', (event) => {
    event.waitUntil(clients.claim());
});

self.addEventListener('fetch', (event) => {
    // We aren't caching internet files, so just pass network requests through
    event.respondWith(fetch(event.request).catch(() => new Response("Offline")));
});
#include "secrets.h"

// --- DELIBERATE COMPILER ERROR ---
// Delete the line below once you have added your real MAC, KEY, and BLOB.
#error "REDACTED: You must replace the REDACTED values with your actual device keys!"

uint8_t MAC[6];
uint8_t DEVICE_KEY[16];
uint8_t BLOB[256];

static uint8_t hex_nibble(char c) {
	if (c >= '0' && c <= '9') return (uint8_t)(c - '0');
	if (c >= 'a' && c <= 'f') return (uint8_t)(c - 'a' + 10);
	if (c >= 'A' && c <= 'F') return (uint8_t)(c - 'A' + 10);
	return 0;
}

static void hex_to_bytes(const char *hex, uint8_t *out, uint16_t len) {
	for (uint16_t i = 0; i < len; i++) {
		out[i] = (uint8_t)((hex_nibble(hex[i * 2]) << 4) | hex_nibble(hex[i * 2 + 1]));
	}
}

void set_device(uint8_t device) {
	uint8_t mac[6] = { 0 };
	uint8_t device_key[16] = { 0 };
	uint8_t blob[256] = { 0 };

	if (1) {
		// [ REDACTED - INSERT YOUR KEYS BELOW ]
		const uint8_t d1_mac[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		const uint8_t d1_key[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		const char *d1_blob_hex = "REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED_REDACTED";
		
		for (int i = 0; i < 6; i++) mac[i] = d1_mac[i];
		for (int i = 0; i < 16; i++) device_key[i] = d1_key[i];
		hex_to_bytes(d1_blob_hex, blob, 256);
	}

	for (int i = 0; i < 6; i++) MAC[i] = mac[i];
	for (int i = 0; i < 16; i++) DEVICE_KEY[i] = device_key[i];
	for (int i = 0; i < 256; i++) BLOB[i] = blob[i];
}
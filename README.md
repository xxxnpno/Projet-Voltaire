# Projet Voltaire

**Projet Voltaire** is a clipboard monitoring program that automatically detects strings in your last clipboard image and sends them to the Reverso API for grammar and spelling corrections. The project uses `cURL` for HTTP requests and `nlohmann/json` for JSON parsing. It also utilizes the Tesseract API to extract strings from screenshots.

## Features

- **Screenshot Text Extraction**: Use the shortcut **Shift + Windows + S** to capture a screenshot and automatically extract text for correction via the Tesseract API.
- **Automated Grammar and Spelling Correction**: Sends clipboard strings to the Reverso API and retrieves corrected text.

## Requirements

- No need for PowerToys anymore. Simply use **Shift + Windows + S** to capture and extract text from the screen.

## How to Use

1. Press **Shift + Windows + S** to take a screenshot.
2. The text will be automatically extracted using Tesseract and sent to the Reverso API for grammar and spelling corrections.
3. The corrected text will be shown in the terminal after processing.

name: Release

on:
  push:
    branches:
    - main
jobs:
  build:
    runs-on: ubuntu-latest
    
    strategy:
      matrix:
        fqbn:
          - esp32:esp32:esp32

    steps:
      - uses: actions/checkout@v3
      - uses: arduino/compile-sketches@v1
        with:
          github-token: ${{ secrets.GITHUB_TOKEN }}
          fqbn: ${{ matrix.fqbn }}
          platforms: |
            - name: esp32:esp32
              source-url: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
          sketch-paths: |
            - iot/iot.ino
            - blynk/blynk.ino
          libraries: |
            - name: ESP32Servo
            - name: Blynk
              version: 1.2.0
            - name : "Adafruit NeoPixel"
          cli-compile-flags: |
            - --warnings="none"

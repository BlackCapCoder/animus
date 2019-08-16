build:
	arduino-cli -b "arduino:samd:arduino_zero_native" compile .

upload:
	arduino-cli -p "/dev/ttyACM0" -b "arduino:samd:arduino_zero_native" upload .

full: build upload
run: full

#!/bin/bash

(for d in `./a.out 0 0`; do
	echo "-- $d";
	(echo "$d" \
		| openssl enc -d -aes-256-cbc -md md5 -a -pass stdin -in data.encrypted -out data.decrypted) \
		&& grep "KEEP YOUR PRIVATE KEYS SAFE" data.decrypted \
		&& exit;
done)


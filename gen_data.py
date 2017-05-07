#!/usr/bin/python

from random import *
from string import ascii_letters

template = '{surname} {initials}\t{class}\n'

with open('input2', 'w') as f:
	for i in range(1, 10 * 1000 * 1000):
		if i % 10000 == 0:
			print i
		f.write(template.format(**{
			'surname': ''.join(choice(ascii_letters) for _ in range(randint(1, 63))),
			'initials': choice(ascii_letters) + choice(ascii_letters),
			'class': str(randint(1, 11))
		}))

# Christoph Cullmann's Layout

Layout with 34 keys

Derived from the standard Planck layout and ideas from the Miryoku layout.

https://github.com/manna-harbour/miryoku

In addition features Achordion to improve the home row modifiers.

https://getreuer.info/posts/keyboards/achordion/index.html

# Generate a JSON keymap file

qmk c2json -km christoph-cullmann -kb planck/rev6_drop --no-cpp keymap.c > keymap_raw.json
qmk format-json keymap_raw.json > keymap.json
rm keymap_raw.json

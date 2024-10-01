# Christoph Cullmann's Layout

Layout with 34 keys based on Miryoku, using Night as base layer:

  night (CN) (8 likes)
    b f l k q  p g o u .
    n s h t m  y c a e i
    x v j d z  ' w ; / ,
          r

  SHAI:
    Alt: 34.36%
    Rol: 42.94%   (In/Out: 22.30% | 20.64%)
    One:  1.97%   (In/Out:  0.58% |  1.38%)
    Rtl: 44.90%   (In/Out: 22.88% | 22.02%)
    Red:  3.01%   (Bad:     0.09%)

    SFB: 0.58%
    SFS: 4.42%    (Red/Alt: 0.78% | 3.64%)

    LH/RH: 49.16% | 50.84%

# How to use

This repository is a valid QMK external userspace as documented here:

 https://docs.qmk.fm/newbs_external_userspace

You need to have a locally setup QMK and use this repo as overlay:

 qmk config user.overlay_dir="/home/cullmann/data/qmk/christoph-cullmann"

To use my keymaps, do for the Corne

 qmk flash -kb crkbd -km christoph-cullmann

or for the Planck

 qmk flash -kb planck/rev6_drop -km christoph-cullmann

# Foundation

Based on ideas and code from:

- https://github.com/manna-harbour/miryoku
- https://github.com/getreuer/qmk-keymap
- https://github.com/filterpaper/qmk_userspace

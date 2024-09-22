# Christoph Cullmann's Layout

Layout with 42 keys based on Miryoku, using Dhorf as base layer:

    dhorf (Oxey)
      v l h k q  j f o u ,
      s r n t w  y c a e i
      z x m d b  p g ' ; .

    SHAI:
      Alt: 31.42%
      Rol: 40.03%   (In/Out: 19.86% | 20.17%)
      One:  1.36%   (In/Out:  0.18% |  1.19%)
      Red:  3.33%   (Bad:     0.11%)

      SFB: 0.70%
      SFS: 5.96%    (Red/Alt: 0.98% | 4.98%)

      LH/RH: 48.52% | 51.48%

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

- https://oxey.dev/dhorf
- https://github.com/manna-harbour/miryoku
- https://github.com/getreuer/qmk-keymap

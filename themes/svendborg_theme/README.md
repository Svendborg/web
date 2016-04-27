svendborg_theme
===============

Sub theme to Svendborg.dk from Bootstrap.

This subtheme uses the other subtheme os2web_bootstrap_theme as parent which is
a Bootstrap child theme.

Requirements
============

- ``sudo apt-get install cairo`` OS X [Cairo](http://cairographics.org/download/)
OR
- ``sudo apt-get install libcairo2-dev`` Linux
- ``sudo npm install -g node-gyp``

Install
=======
0. Install requirements
1. ``npm install``
2. ``npm install grunt-spritesmith``
2. ``grunt build`` | ``grunt watch`` | ``grunt sprite``

Sprites
=======

Use sprites by adding png images into images/sprites/ folder, and run either
``grunt build`` or ``grunt sprite`` command.

Sprites are automatically generated into the ``images/sprites.png`` file and
less in ``less/sprites.less`` file.

See documentation in ``less/sprites.less`` for how to use them.
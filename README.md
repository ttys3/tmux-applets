------------
tmux-applets
------------

 * tmux-cpu-freq  -  show cpu frequencies as coloured boxes

 * tmux-ping	  -  show results of pinging a host as coloured boxes

 * tmux-mem	  -  show memory usage as a coloured box

Currently tmux-cpu-freq requires Linux 2.6+ and tmux-mem requires
Linux 2.4+. If you are able to port them to other kernels please
send me patches or a pull request :-)


Installation
------------

Edit the Makefile to your needs. You may wish to change the INSTALL_DIR
and CFLAGS if you wish...

Then run:
	$ make
	$ make install

To make static binaries:

```bash
make CFLAGS=-static
```

Usage in tmux
-------------
	
In ~/.tmux.conf, edit your status line:

	set status-right "#(/path/to/applet <arguments>) #(/path/to/applet2 <arguments>)"

For example, in my configuration I have:

	set status-right "#(/home/lucas/bin/tmux-cpu-freq 6)  "
	set status-interval 1


tmux-cpu-freq
-------------

	Usage:
		tmux-cpu-freq [<number-of-cpus>]

Or, you can edit NUMBER_CPUS in tmux-cpu-freq.c before compiling it.

You can also customise the colours by editing the level_colours array,
and adjusting MAX_LEVEL_COLOURS if need be.

The reason this configuration is static is since tmux must run the applet
every frequency interval, thus speed is paramount.


tmux-ping
---------

	Usage:
		tmux-ping <host>

You can change the colours by editing COLOUR_OKAY and COLOUR_ERROR in
tmux-ping.c


tmux-mem
--------

	Usage:
		tmux-mem

Colours can be customised by editing the level_colours array, and adjusting
MAX_LEVEL_COLOURS if need be.


Contact
-------

Bug reports, etc can be sent to < lmartinking@gmail.com >, or you can use
the github page at: < https://github.com/lmartinking/tmux-applets/issues >

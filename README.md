<h2> WebToolKit C++ on TRIK</h2>

About wt: http://www.webtoolkit.eu/wt

Widget gallery: http://www.webtoolkit.eu/widgets

About TRIK http://blog.trikset.com/

<h2>Crosscompile wt-projects for TRIK:</h2>

<h3>Auto-compile</h3>
Just run 

	bash install

<h3>Manual compile</h3>

Use this steps:

	wget -c http://kent.dl.sourceforge.net/sourceforge/witty/wt-3.3.2.tar.gz
	tar xvxf wt-3.3.2.tar.gz
	cd wt-3.3.2
	mkdir buildtrik
	cd buildtrik
	source /opt/trik-sdk/environment-setup-armv5te-oe-linux-gnueabi

About trik-sdk: https://github.com/trikset/trikRuntime/wiki/%D0%9D%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B9%D0%BA%D0%B0-%D1%80%D0%B0%D0%B1%D0%BE%D1%87%D0%B5%D0%B3%D0%BE-%D0%BE%D0%BA%D1%80%D1%83%D0%B6%D0%B5%D0%BD%D0%B8%D1%8F

	cmake .. -DSHARED_LIBS=OFF -DBOOST_PREFIX=/opt/trik-sdk/sysroots/armv5te-oe-linux-gnueabi/usr/ -DWT_CPP_11_MODE=-std=c++0x -DWT_SIGNALS_IMPLEMENTATION=boost.signals2 -DENABLE_SQLITE=OFF -DENABLE_POSTGRES=OFF

The SHARED_LIBS=OFF option makes the Wt libraries static. This is not required, but easier for deployment: you can simply copy the example executables to your TRIK without having to worry about the shared libraries.

ONLY if you have problems with boost-random copy files to sdk
 
	cd wt-trik/boost_random
	cp libboost_random* /opt/trik-sdk/sysroots/armv5te-oe-linux-gnueabi/usr/lib/

Make lib and examples

	make
	make -C examples

<h2>Deployment to the TRIK</h2>

<h3>Auto-deploy</h3>	
Just run

	bash deploy

<h3>Manual deploy</h3>

Copy *.wt file to your TRIK. And then start it with your IP and your port!

	e.g.:	./*.wt --docroot . --http-address 192.168.0.114 --http-port 8080

And ONLY if you have problems with boost-random copy files to your TRIK with your IP.

	cd wt-trik/boost_random
	scp libboost_random* root@192.168.0.114:/usr/lib

And ONLY if you have problems with other boost libs

	scp /opt/trik-sdk/sysroots/armv5te-oe-linux-gnueabi/usr/lib/libboost_* root@192.168.0.114:/usr/lib






ip:
	gcc ip.c -march=atom -O4 -pipe -lfcgi -o ip

install:
	cp -f ip /usr/local/sbin/ip-fastcgi
	cp -f ip_fastcgi /etc/init.d/

clean:
	rm -f ip

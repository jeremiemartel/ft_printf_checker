How to launch tests:

	*	Modify the variable LIBPATH in Makefile, with the path to your project

	*	make && make test || make && ./libunit-test


How to use tester:

	*	you can modify tests launched in main.c or in any 00_launcher.c file

This tester cannot substitute manual tests and human correctors.

For any issues or questions contact me on slack : jmartel, or by emails: jmartel@student.42.fr

NB:
I had some questions on what dprintf is and how are the tests made. So, here is the principle : I'm opening two pipes, on stdin and stderr, calling ft_printf and dprintf(2, ...), where dprintf is the version of ft_printf writing on any file descriptor. Then I'm just comparing the result, written in both pipes.

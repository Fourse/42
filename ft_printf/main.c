/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:29:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/07/20 17:45:26 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>
int		main(void)
{
	//int a = 10;
//?test part
	//!format d
	// //printf("format d\n");
	// ft_printf("%ld");
	// ft_printf("%lld");
	// ft_printf("%hd");
	// ft_printf("%hhd");
	// ft_printf("%jd");
	// ft_printf("%zd");
	// ft_printf("%Ld");
	// // //!format i
	// //printf("format i\n");
	// ft_printf("%li");
	// ft_printf("%lli");
	// ft_printf("%hi");
	// ft_printf("%hhi");
	// ft_printf("%ji");
	// ft_printf("%zi");
	// ft_printf("%Li");
	// //!format o
	// //printf("format o\n");
	// ft_printf("%lo");
	// ft_printf("%llo");
	// ft_printf("%ho");
	// ft_printf("%hho");
	// ft_printf("%jo");
	// ft_printf("%zo");
	// //!format x
	// //printf("format x\n");
	// ft_printf("%lx");
	// ft_printf("%llx");
	// ft_printf("%hx");
	// ft_printf("%hhx");
	// ft_printf("%jx");
	// ft_printf("%zx");
	// //!format u
	// //printf("format u\n");
	// ft_printf("%lu");
	// ft_printf("%llu");
	// ft_printf("%hu");
	// ft_printf("%hhu");
	// ft_printf("%ju");
	// ft_printf("%zu");
	// //!format f
	// //printf("format f\n");
	// ft_printf("%lf");
	// ft_printf("%llf");
	// ft_printf("%hf");
	// ft_printf("%hhf");
	// ft_printf("%jf");
	// ft_printf("%zf");
	// ft_printf("%Lf");
	// //!format g
	// //printf("format g\n");
	// ft_printf("%lg");
	// ft_printf("%llg");
	// ft_printf("%hg");
	// ft_printf("%hhg");
	// ft_printf("%jg");
	// ft_printf("%zg");
	// ft_printf("%Lg");
	// //!format G
	// //printf("format G\n");
	// ft_printf("%lG");
	// ft_printf("%llG");
	// ft_printf("%hG");
	// ft_printf("%hhG");
	// ft_printf("%jG");
	// ft_printf("%zG");
	// ft_printf("%LG");
	// ////printf("hello %w %f\n", 10, 5.1);
	// ft_printf("hello world %24.10d wow", 2);
	// ft_printf("a = %x b = %x c = %x\n", 20, 15, 10);
	//!D format
	//printf("% .5d", -10);
	// ft_printf("%2d\n", a);
	// ft_printf("%1.10d\n", 15);
	//printf("------------test1-------------\n");
	// ft_printf("%6.10d\n", 1234);
	//printf("%6.10d\n", 1234);

	//printf("------------test2-------------\n");
	// ft_printf("%3.2d\n", 1234);
	//printf("%3.2d\n", 1234);

	//printf("------------test3-------------\n");
	// ft_printf("%2.4d\n", 1234);
	//printf("%2.4d\n", 1234);

	//printf("------------test4-------------\n");
	// ft_printf("%10.5d\n", 1234);
	//printf("%10.5d\n", 1234);

	//printf("------------test5-------------\n");
	// ft_printf("%10.3d\n", 1234);
	//printf("%10.3d\n", 1234);

	//printf("------------test6-------------\n");
	// ft_printf("%3.10d\n", 1234);
	//printf("%3.10d\n", 1234);

	//printf("%,*.d", 5, 4);
	//printf("test7\n");
	// ft_printf("%d\n", 0);
	// ft_printf("a=%10d\nb=%d\n", 25, 123);
	//printf("a = %10.d\nb = %d\n", 25, 31);
	// ft_printf("a = %20.d\nb = %d\n", 25, 31);
	// ft_printf("hello %+-15.10d world\n", 123);
	// printf("hello %+-15.10d world\n", 123);
	// printf("--------test1.1----------\n");
	// printf("hiw are you? % -20.5d hmm?\nfine %-+15.5d\n", -321, 45);
	// ft_printf("hiw are you? % -20.5d hmm?\nfine %-+15.5d\n", -321, 45);
	//printf("--------test2.1----------\n");
	//printf("hello %15.10d world\na = %+10.5d\n", 123, 45);
	// ft_printf("hello %15.10d world\na = %+10.5d\n", 123, 45);
	//printf("--------test3.1----------\n");
	//printf("%+d\n", 0);
	// ft_printf("%+d\n", 0);
	// ft_printf("%#llx\n", -143);
	//printf("%#llx\n", -143);
	// ft_printf("%#x\n", 0);
	//printf("%#.5x\n", 0);

	//!  tests for spec "d"
	// printf("*******************************\n");
	// printf("************d_FORMAT***********\n");
	// printf("*******************************\n\n");

	// printf("------------test1-------------\n");
	// assert(ft_printf("%#.10d\n", 1234) && printf("%#.10d\n", 1234));

	// printf("------------test2-------------\n");
	// assert(ft_printf("%3###---.2d\n", 1234) && printf("%3###---.2d\n", 1234));

	// printf("------------test3-------------\n");
	// assert(ft_printf("%--+++--10.40d\n", 1234) && printf("%--+++--10.40d\n", 1234));

	// printf("------------test4-------------\n");
	// assert(ft_printf("%##....4..4lld\n", 1234) && printf("%##....4..4lld\n", 1234));

	// printf("------------test5-------------\n");
	// assert(ft_printf("%0d\n", 1234) && printf("%0d\n", 1234));

	// printf("------------test6-------------\n");
	// assert(ft_printf("%.0d\n", 1234) && printf("%.0d\n", 1234));

	// printf("------------test7-------------\n");
	// assert(ft_printf("%#010.10d\n", 1234) && printf("%#010.10d\n", 1234));

	// printf("------------test8-------------\n");
	// assert(ft_printf("%-10.10d\n", 1234) && printf("%-10.10d\n", 1234));

	// printf("------------test9-------------\n");
	// assert(ft_printf("%+++10.40d\n", 1234) && printf("%+++10.40d\n", 1234));

	// printf("------------test10-------------\n");
	// assert(ft_printf("%;+..4..4hd\n", 1234) && printf("%;+..4..4hd\n", 1234));

	// printf("------------test11-------------\n");
	// assert(ft_printf("%020.10d\n", 1234) && printf("%020.10d\n", 1234));

	// printf("------------test12-------------\n");
	// assert(ft_printf("%0d\n", 0) && printf("%0d\n", 0));

	// printf("------------test13-------------\n");
	// assert(ft_printf("%+..4..4hd\n", 0) && printf("%+..4..4hd\n", 0));

	// printf("------------test14-------------\n");
	// assert(ft_printf("|%020.0d|\n", 0) && printf("|%020.0d|\n", 0));

	// printf("------------test15-------------\n");
	// assert(ft_printf("|%0.d|\n", 0) && printf("|%0.d|\n", 0));

	// printf("------------test16-------------\n");
	// assert(ft_printf("%0d\n", -1) && printf("%0d\n", -1));

	// printf("------------test17-------------\n");
	// assert(ft_printf("%;+..4..4hd\n", -1) && printf("%;+..4..4hd\n", -1));

	// printf("------------test18-------------\n");
	// assert(ft_printf("%020.0d\n", -1) && printf("%020.0d\n", -1));

	// printf("------------test19-------------\n");
	// assert(ft_printf("%0.d\n", -1) && printf("%0.d\n", -1));

	// printf("------------test20-------------\n");
	// assert(ft_printf("%-+10.5d\n", 31) && printf("%-+10.5d\n", 31));

	// printf("------------test21-------------\n");
	// assert(ft_printf("%-+5.10d\n", 31) && printf("%-+5.10d\n", 31));

	// printf("------------test22-------------\n");
	// assert(ft_printf("%+10.5d\n", 31) && printf("%+10.5d\n", 31));

	// printf("------------test23-------------\n");
	// assert(ft_printf("%+5.10d\n", 31) && printf("%+5.10d\n", 31));

	// printf("------------test24-------------\n");
	// assert(ft_printf("%-+10.1dw\n", 31) && printf("%-+10.1dw\n", 31));

	// printf("------------test25-------------\n");
	// assert(ft_printf("%+10.1dw\n", 31) && printf("%+10.1dw\n", 31));

	// printf("------------test26-------------\n");
	// assert(ft_printf("% 5.10dw\n", 31) && printf("% 5.10dw\n", 31));

	// printf("------------test27-------------\n");
	// assert(ft_printf("%02.dw\n", 31) && printf("%02.dw\n", 31));

	// printf("------------test28-------------\n");
	// assert(ft_printf("% 10.dw\n", -31) && printf("% 10.dw\n", -31));

	// printf("------------test29-------------\n");
	// assert(ft_printf("%+10.hdw\n", 31) && printf("%+10.hdw\n", 31));

	// // // //!  tests for spec "x/X"
	// // !  tests for spec "x/X"

	// printf("*******************************\n");
	// printf("************X_FORMAT***********\n");
	// printf("*******************************\n\n");

	// printf("------------test1-------------\n");
	// assert(ft_printf("|%020x|\n", 1234) && printf("|%020x|\n", 1234));

	// printf("------------test2-------------\n");
	// assert(ft_printf("|%#0.20x|\n", 1234) && printf("|%#0.20x|\n", 1234));

	// printf("------------test3-------------\n");
	// assert(ft_printf("|%0.0x|\n", 1234) && printf("|%0.0x|\n", 1234));

	// printf("------------test4-------------\n");
	// assert(ft_printf("|%20.4x|\n", 1234) && printf("|%20.4x|\n", 1234));

	// printf("------------test5-------------\n");
	// assert(ft_printf("|%4.5x|\n", 1234) && printf("|%4.5x|\n", 1234));

	// printf("------------test6-------------\n");
	// assert(ft_printf("|%-20x|\n", 1234) && printf("|%-20x|\n", 1234));

	// printf("------------test7-------------\n");
	// assert(ft_printf("|%0x|\n", 0) && printf("|%0x|\n", 0));

	// printf("------------test8-------------\n");
	// assert(ft_printf("|%#x|\n", 0) && printf("|%#x|\n", 0));

	// printf("------------test9-------------\n");
	// assert(ft_printf("|%.1x|\n", 0) && printf("|%.1x|\n", 0));

	// printf("------------test10-------------\n");
	// assert(ft_printf("|%03.0x|\n", 0) && printf("|%03.0x|\n", 0));

	// printf("------------test11-------------\n");
	// assert(ft_printf("|%#5x|\n", 0) && printf("|%#5x|\n", 0));

	// printf("------------test12-------------\n");
	// assert(ft_printf("|%#-10x|\n", 0) && printf("|%#-10x|\n", 0));

	// printf("------------test13-------------\n");
	// assert(ft_printf("%+..4..4hd\n", 0) && printf("%+..4..4hd\n", 0));

	// printf("------------test14-------------\n");
	// assert(ft_printf("|%x|\n", 0) && printf("|%x|\n", 0));

	// printf("------------test15-------------\n");
	// assert(ft_printf("|%#x|\n", 0) && printf("|%#x|\n", 0));

	// printf("------------test16-------------\n");
	// assert(ft_printf("|%#-20.10x|\n", 0) && printf("|%#-20.10x|\n", 0));

	// printf("------------test17-------------\n");
	// assert(ft_printf("%;+..4..4hd\n", -1) && printf("%;+..4..4hd\n", -1));

	// printf("------------test18-------------\n");
	// assert(ft_printf("|%#.x|\n", 1234) && printf("|%#.x|\n", 1234));

	// printf("------------test19-------------\n");
	// assert(ft_printf("|%#-20x|\n", 1) && printf("|%#-20x|\n", 1));

	// printf("------------test20-------------\n");
	// assert(ft_printf("|%#20x|\n", 1) && printf("|%#20x|\n", 1));

	// //! tests for spes "o"

	// printf("*******************************\n");
	// printf("************O_FORMAT***********\n");
	// printf("*******************************\n\n");

	// printf("------------test1-------------\n");
	// assert(ft_printf("|%020o|\n", 1234) && printf("|%020o|\n", 1234));

	// printf("------------test2-------------\n");
	// assert(ft_printf("|%#020o|\n", 1234) && printf("|%#020o|\n", 1234));

	// printf("------------test3-------------\n");
	// assert(ft_printf("|%0.0o|\n", 1234) && printf("|%0.0o|\n", 1234));

	// printf("------------test4-------------\n");
	// assert(ft_printf("|%20.4o|\n", 1234) && printf("|%20.4o|\n", 1234));

	// printf("------------test5-------------\n");
	// assert(ft_printf("|%4.5o|\n", 1234) && printf("|%4.5o|\n", 1234));

	// printf("------------test6-------------\n");
	// assert(ft_printf("|%-20o|\n", 1234) && printf("|%-20o|\n", 1234));

	// printf("------------test7-------------\n");
	// assert(ft_printf("|%0o|\n", 0) && printf("|%0o|\n", 0));

	// printf("------------test8-------------\n");
	// assert(ft_printf("|%#o|\n", 0) && printf("|%#o|\n", 0));

	// printf("------------test9-------------\n");
	// assert(ft_printf("|%.1o|\n", 0) && printf("|%.1o|\n", 0));

	// printf("------------test10-------------\n");
	// assert(ft_printf("|%03.0o|\n", 0) && printf("|%03.0o|\n", 0));

	// printf("------------test11-------------\n");
	// assert(ft_printf("|%#5o|\n", 0) && printf("|%#5o|\n", 0));

	// printf("------------test12-------------\n");
	// assert(ft_printf("|%#-10o|\n", 0) && printf("|%#-10o|\n", 0));

	// printf("------------test13-------------\n");
	// assert(ft_printf("%+..4..4hd\n", 0) && printf("%+..4..4hd\n", 0));

	// printf("------------test14-------------\n");
	// assert(ft_printf("|%o|\n", 0) && printf("|%o|\n", 0));

	// printf("------------test15-------------\n");
	// assert(ft_printf("|%#o|\n", 0) && printf("|%#o|\n", 0));

	// printf("------------test16-------------\n");
	// assert(ft_printf("|%-20.10o|\n", 0) && printf("|%-20.10o|\n", 0));

	// printf("------------test17-------------\n");
	// assert(ft_printf("%;+..4..4hd\n", -1) && printf("%;+..4..4hd\n", -1));

	// printf("------------test18-------------\n");
	// assert(ft_printf("|%#.o|\n", 1234) && printf("|%#.o|\n", 1234));

	// printf("------------test19-------------\n");
	// assert(ft_printf("|%-20o|\n", 1) && printf("|%-20o|\n", 1));

	// printf("------------test20-------------\n");
	// assert(ft_printf("|%#.o|\n", 0) && printf("|%#.o|\n", 0));

	// printf("------------test21-------------\n");
	// assert(ft_printf("|%-20.0o|\n", 0) && printf("|%-20.0o|\n", 0));

	// printf("------------test22-------------\n");
	// assert(ft_printf("|%#10.o|\n", 0) && printf("|%#10.o|\n", 0));

	// printf("------------test23-------------\n");
	// assert(ft_printf("|%.o|\n", 0) && printf("|%.o|\n", 0));

	// printf("------------test24-------------\n");
	// assert(ft_printf("%-+020.10X\n", 4123453) && printf("%-+020.10X\n", 4123453));
	// //printf("%0+-#20.20w %d\n", 45);
	// //printf("%-10w hello world %010y    how are yoU?\n");
	// //printf("%20zw %dhello\n", 10);
	// ft_printf("%20zw %dhello\n", 10);

	// //printf("%d\n", 10);
	// ft_printf("%d\n", 10);

	// //printf("%w hello world\n");
	// ft_printf("%w hello world\n");

	// //printf("%ll.,d", 34);
	// ft_printf("%$\n", 45);
	// //*Не проходит
	// printf("------------test25-------------\n");
	// assert(ft_printf("%;:+hh-;h: h0.10.10 lld\n", 45) && printf("%;:+hh-;h: h0.10.10 lld\n", 45));
	// //printf("%*.*13d", 1, 10, 5);
	// //printf("%*.*d", 13);
	// //printf("%HHd\n", 34);
	// ft_printf("%20.20\n");
	// //printf("%.*.*.*d", 13, 13, 5, 42);
	// //printf("%td\n", 45);
	// ft_printf("%*.*d\n", 13, 25, 13);
	// //printf("%4.*dworld", -10, 13);
	// //printf("%$d\n", 45);
	// //printf("%2$d\n", 45, 45);
	// //printf("intmax_t = %ld\n", sizeof(intmax_t));
	// //printf("ptrdiff_t = %ld\n", sizeof(ptrdiff_t));
	// //printf("size_t = %ld\n", sizeof(size_t));
	// ft_printf("%Lhhd", 23);
	// ft_printf("%hhO\n", 23);
	// ft_printf("% +d", 23);
	// //printf("%hhO\n", 23.1);
	// //printf("\n");
	// //printf("%**.*d\n", 2, 14, 10, 3, 10);
	// ft_printf("%**.*d\n", 2, 14, 10, 3, 10);
	// //printf("%", 43);

	// ft_printf("%*.*d\n", -10, 20);

	// ft_printf("%c");
	// ft_printf("%hc");
	// ft_printf("%hhc");
	// ft_printf("%lc");
	// ft_printf("%llc");
	// ft_printf("%jc");
	// ft_printf("%zc");
	// ft_printf("%Lc");

	// ft_printf("%s");
	// ft_printf("%hs");
	// ft_printf("%hhs");
	// ft_printf("%ls");
	// ft_printf("%lls");
	// ft_printf("%js");
	// ft_printf("%zs");
	// ft_printf("%Ls");

	// ft_printf("%S");
	// ft_printf("%hS");
	// ft_printf("%hhS");
	// ft_printf("%lS");
	// ft_printf("%llS");
	// ft_printf("%LS");
	// ft_printf("%jS");
	// ft_printf("%zS");
	// ft_printf("%LS");

	// ft_printf("%C");
	// ft_printf("%hC");
	// ft_printf("%hhC");
	// ft_printf("%lC");
	// ft_printf("%llC");
	// ft_printf("%LC");
	// ft_printf("%jC");
	// ft_printf("%zC");
	// ft_printf("%LC");
	//ft_printf("a = %x\n", 16);
	//ft_printf("%c", 'c');
	//ft_printf("%s %s %c\n", str, str1, n);
	//ft_printf("a = %d b = %d c = %d\n", 13, 14, 25);
	//printf("%20.4s", "hello world");
	//!SRING BEGIN
		//? Флаг '-' работает для строки
		//? Ширина работает так же как и для целых чисел.
		//? Точность режет строку, если она меньше размера строки
		//? Звездочку поддерживает и для точности и для ширины
		//?
	//!STRING END

	//ft_printf("%020.18s", "hello world");
	//printf("%020.10s", "hello");
	//ft_printf("%20.10s", "hello world\n");
	//printf("%11.5s", "hello world"); //?size_num = 11;
//!TEST_STRING_BEGING
	// printf("***************************\n");
	// printf("********TEST_STRING********\n");
	// printf("***************************\n");

	// printf("===========TEST1===========\n");
	// ft_printf("%20.13s", "hello world"); //?size_num = 11;
	// printf("\n");
	// printf("%20.13s", "hello world");
	// printf("\n");

	// printf("===========TEST2===========\n");
	// ft_printf("%13.20s", "hello world");
	// printf("\n");
	// printf("%13.20s", "hello world");
	// printf("\n");

	// printf("===========TEST3===========\n");
	// ft_printf("%11.20s", "hello world");
	// printf("\n");
	// printf("%11.20s", "hello world");
	// printf("\n");

	// printf("===========TEST4===========\n");
	// ft_printf("%15.5s", "hello world");
	// printf("\n");
	// printf("%15.5s", "hello world");
	// printf("\n");

	// printf("===========TEST5===========\n");
	// ft_printf("%11.5s", "hello world");
	// printf("\n");
	// printf("%11.5s", "hello world");
	// printf("\n");

	// printf("===========TEST6===========\n");
	// ft_printf("%5.7s", "hello world");
	// printf("\n");
	// printf("%5.7s", "hello world");
	// printf("\n");

	// printf("===========TEST7===========\n");
	// ft_printf("%13.4s", "hello world");
	// printf("\n");
	// printf("%13.4s", "hello world");
	// printf("\n");

	// printf("===========TEST8===========\n");
	// ft_printf("test_string: %20.sw\n", "one two tree");
	// printf("test_string: %20.sw\n", "one two tree");

	// printf("===========TEST9===========\n");
	// ft_printf("test_string: %020sw\n", "one two tree");
	// printf("test_string: %020sw\n", "one two tree");

	// printf("===========TEST10==========\n");
	// ft_printf("test_string: %-020.sw\n", "one two tree");
	// printf("test_string: %-020.sw\n", "one two tree");
//!TEST_STRING_END

	//printf("a = %d\nstring = %s\n", 14, "work to fork");
	//ft_printf("a = %d\nstring = %s\n", 14, "work to fork");

	//ft_printf("%s\n", "test");

	//ft_printf("%.s", "hello world");
	//printf("%.s", "hello world");
	//printf("%.s\n", "hello world");
	//ft_printf("size_write = %d\n", g_spec.size_write);

//!TEST_CHAR_BEGIN
// 	printf("***************************\n");
// 	printf("********TEST_CHAR**********\n");
// 	printf("***************************\n");

// 	printf("===========TEST1===========\n");
// 	printf("%-102cw\n", 'a');
// 	ft_printf("%-102cw\n", 'a');

// 	printf("===========TEST2===========\n");
// 	printf("%c\n", 'c');
// 	ft_printf("%c\n", 'c');

// 	printf("===========TEST4===========\n");
// 	printf("");
// // !TEST_CHAR_END
// 	printf("======TEST8======\n");
// 	ft_printf("a = %10.5d\nb = %13d\nchar = %-2chow\n string: %-13.4s\n", 14, 29, 'w', "hello world");
// 	printf("a = %10.5d\nb = %13d\nchar = %-2chow\n string: %-13.4s\n", 14, 29, 'w', "hello world");
// 	ft_printf("string:\n%s\nchar = %c\n", "hello world", 'w');
// 	printf("string:\n%s\nchar = %c\n", "hello world", 'w');

// 	ft_printf("string:\n%s\na = %10.5d\nchar = %c\n", "hello world", 45, 'w');
// 	printf("string:\n%s\na = %10.5d\nchar = %c\n", "hello world", 45, 'w');
// 	ft_printf("a = %10.5d\nb = %13d\nchar = %c\n", 14, 29, 'w');
// 	// ft_printf("a = %10.5d\nchar = %c\n" string: %-13.4s\n", 14, 29, 'w'", "hello world");
// 	ft_printf("a = %d\nb = %c\n", 34, 'w');
// 	ft_printf("char = %13c\n", 'w');

// 	ft_printf("a = %c\nb = %c\nc = %10-c\nstring = %-023c\n", 'a', 'w', 'j', 'e');
// 	printf("a = %c\nb = %c\nc = %10-c\nstring = %-023c\n", 'a', 'w', 'j', 'e');

//!UNIT_TESTS_BEGIN
	// printf("UNIT_TESTS_BEGIN\n");
	// __TEST__return_printf(0);
	// printf("UNIT_TESTS_END\n");

	// __TEST__check_ft_ismy(0);
//!UNIT_TESTS_END
	//printf("a = %+013d\nb = %10c\nstring: %20.4s\n", 13, 'o', "hello world");
	//ft_printf("a = %+013d\nb = %10c\nstring: %20.4s\n", 13, 'o', "hello world");

	// printf("%*.*d\n", 20, 5, 16);
	// ft_printf("%*.*d\n", 20, 5, 16);

	//ret = ft_printf("test string %s\n", "this is test string");
	//ft_printf("%20chow are you?\n", 'a');

	//char *test;

	//test = NULL;
	//write(1, test, 5);
	//ft_printf("helo world %-20sfine and you?\n", "how are you?");
	//ft_printf("symbal = %010c\nstrind: %0shello\n", 'w', "test_string");
	//printf("symbal = %010c\nstrind: %0shello\n", 'w', "test_string");
	//printf("hello%n\n", n);
	//printf("n = %d\n", *n);
	// printf("hello %n\n", n);
	// printf("n = %d\n", *n);
	// ft_printf("hello %n\n", n);
	// printf("n = %d\n", *n);
	// ft_printf("test char: %20c\n", 'w');
	// printf("test char: %20c\n", 'w');
	//printf("testing %m");

//!TEST_N_BEGIN
	// char a;
	// char *p_a;

	// short a;
	// short *p_a;

	// int a;
	// int *p_a;

	// long int a;
	// long int *p_a;



	// long long int a;
	// long long int *p_a;

	// intmax_t a;
	// intmax_t *p_a;

	// ssize_t a;
	// ssize_t *p_a;

	// ptrdiff_t a;
	// ptrdiff_t *p_a;
	//p_a = &a;
	//ft_printf("hello world %ln\n", p_a);
	//printf("p_a = %ld\n", a);
//!TEST_N_END

	//extern char *strerror;
	//printf("%s\n", strerror(errno));
	//printf("%10m\n");
	//ft_printf("hello world%10n\n", n);
	//printf("size = %d\n", *n);
	//printf("%10.2m");
	// ft_printf("test string %n how are you?\n", n);
	// printf("n = %d\n", *n);

	// printf("test string %n how are you?\n", n);
	// printf("n = %d\n", *n);

	//ft_printf("%whow are you?\n", 43);
	//printf("%whow are you?\n", 43);
	//printf("%m");

	// printf("%d\n", 34);
	// ft_printf("%d\n", 34);

	// printf("hello world %20.10d\n", 13);
	// ft_printf("hello world %20.10d\n", 13);

	// ft_printf("%20.1d %.1d %d %lld\n", 13, 14, 24, 100);
	// printf("%20.1d %.1d %d %lld\n", 13, 14, 24, 100);

	//ft_printf("%d %d\n", 192, 31);

	// printf("===========TEST for o ===========\n");
	// ft_printf("%5.3o\n", 4);
	// printf("%5.3o\n", 4);

	// printf("===========TEST for x ===========\n");
	// ft_printf("%#.10x\n", 1);
	// printf("%#.10x\n", 1);

	// 	printf("===========TESTs for b ===========\n");
	// ft_printf("|%20b|\n", 1);
	// printf("|%20o|\n", 1);

	// printf("%.1f", 1234567890123456789012345678901234567890.4);

	//printf("mem+rec = %d\n", ft_mem_rec_cmp_for_color("red", "red", 3));
	//ft_printf("hello world\n");
	//ft_printf("{/red:greasy}hello world");
	// char str[100] = "hello world";
	// char str2 = "[;32";
	// char str1[100] = "\e";

	// ft_strcpy(str, "\e");
	// ft_strcat(str, "[;32m");
	// printf("str = %d\n", *(str + 1));
	//ft_strcat(str, "hello world");
	//printf(str);
	//printf("\e[;32mtetsing\n");
	//printf(str);
	//ft_printf("{/red:greasy}");
	//str = ft_strjoin("[32;3m", "hello world");
	//printf(str);
	//printf("\033[;32;4mtesting";

	//ft_printf("{/red}");
	//ft_printf("%%hello world");
	//printf("%m");
	//printf("wowowowowowo");
	//printf("%%d\n", 34);
	//ft_printf("%%d tessting\n", 23);
	//printf("%w testing\n");
	//ft_printf("%w testing\n");
//	int ret_printf[3];

	// printf("%%%%dello wolrd\na = %d\n", 123, 32);
	// ft_printf("%%%%dello world\na = %d\n", 123, 32);

	// ret_printf[0] = ft_printf("ajeliafj;selifja\n");
	// ret_printf[1] = ft_printf("hfahahaha\n");
	// ret_printf[2] = ft_printf("{/%%} hello world\n");
	// printf("1) %d\n2) %d\n3) %d\n", ret_printf[0], ret_printf[1], ret_printf[2]);

	// ret_printf[0] = ft_printf("hello {/red} world\n");
	// printf("ret_printf = %d\n", ret_printf[0]);

	// ret_printf[0] = ft_printf("testing string: %s\n", "lalalal ahahah how are you?\n");
	// ret_printf[1] = printf("testing string: %s\n", "lalalal ahahah how are you?\n");
	// assert(ret_printf[0] && ret_printf[1]);
	// printf("ret_printf = %d\n", ret_printf[0]);

//	int fd;

	// fd = open("testing", O_WRONLY);
	// //printf("fd = %d\n", fd);
	// //ft_printf("hello %v word how are you?\n", fd);
	// ft_printf("ёу %vпривет {/red} миир как у тебя дела, я ебанутый потому что я общаюсь с миром\n", fd);
	// close(fd);

	// int sq;
	// sq = 0;
	//ft_printf("%r\n", 'w');
// 	while (sq < 33)
// 		ft_printf("%d) %r\n", sq, sq++);
// 	return (0);
// ft_printf("%S\n", L"ݗݜशব");
  while (1);
  return (0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:29:21 by rloraine          #+#    #+#             */
/*   Updated: 2019/06/30 13:59:12 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	//int a = 10;
//?test part
	//!format d
	// //printf("or: format d\n");
	// ft_printf("ft: %ld");
	// ft_printf("ft: %lld");
	// ft_printf("ft: %hd");
	// ft_printf("ft: %hhd");
	// ft_printf("ft: %jd");
	// ft_printf("ft: %zd");
	// ft_printf("ft: %Ld");
	// // //!format i
	// //printf("or: format i\n");
	// ft_printf("ft: %li");
	// ft_printf("ft: %lli");
	// ft_printf("ft: %hi");
	// ft_printf("ft: %hhi");
	// ft_printf("ft: %ji");
	// ft_printf("ft: %zi");
	// ft_printf("ft: %Li");
	// //!format o
	// //printf("or: format o\n");
	// ft_printf("ft: %lo");
	// ft_printf("ft: %llo");
	// ft_printf("ft: %ho");
	// ft_printf("ft: %hho");
	// ft_printf("ft: %jo");
	// ft_printf("ft: %zo");
	// //!format x
	// //printf("or: format x\n");
	// ft_printf("ft: %lx");
	// ft_printf("ft: %llx");
	// ft_printf("ft: %hx");
	// ft_printf("ft: %hhx");
	// ft_printf("ft: %jx");
	// ft_printf("ft: %zx");
	// //!format u
	// //printf("or: format u\n");
	// ft_printf("ft: %lu");
	// ft_printf("ft: %llu");
	// ft_printf("ft: %hu");
	// ft_printf("ft: %hhu");
	// ft_printf("ft: %ju");
	// ft_printf("ft: %zu");
	// //!format f
	// //printf("or: format f\n");
	// ft_printf("ft: %lf");
	// ft_printf("ft: %llf");
	// ft_printf("ft: %hf");
	// ft_printf("ft: %hhf");
	// ft_printf("ft: %jf");
	// ft_printf("ft: %zf");
	// ft_printf("ft: %Lf");
	// //!format g
	// //printf("or: format g\n");
	// ft_printf("ft: %lg");
	// ft_printf("ft: %llg");
	// ft_printf("ft: %hg");
	// ft_printf("ft: %hhg");
	// ft_printf("ft: %jg");
	// ft_printf("ft: %zg");
	// ft_printf("ft: %Lg");
	// //!format G
	// //printf("or: format G\n");
	// ft_printf("ft: %lG");
	// ft_printf("ft: %llG");
	// ft_printf("ft: %hG");
	// ft_printf("ft: %hhG");
	// ft_printf("ft: %jG");
	// ft_printf("ft: %zG");
	// ft_printf("ft: %LG");
	// ////printf("or: hello %w %f\n", 10, 5.1);
	// ft_printf("ft: hello world %24.10d wow", 2);
	// ft_printf("ft: a = %x b = %x c = %x\n", 20, 15, 10);
	// ////printf("or: % .5d", -10);
	// ft_printf("ft: %2d\n", a);
	// ft_printf("ft: %1.10d\n", 15);
	// ////printf("------------test1-------------\n");
	// ft_printf("ft: %6.10d\n", 1234);
	// //printf("or: %6.10d\n", 1234);

	// printf("------------test2-------------\n");
	// ft_printf("ft: %3.2d\n", 1234);
	// printf("or: %3.2d\n", 1234);

	// printf("------------test3-------------\n");
	// ft_printf("ft: %2.4d\n", 1234);
	// printf("or: %2.4d\n", 1234);

	// printf("------------test4-------------\n");
	// ft_printf("ft: %10.5d\n", 1234);
	// printf("or: %10.5d\n", 1234);

	// printf("------------test5-------------\n");
	// ft_printf("ft: %10.3d\n", 1234);
	// printf("or: %10.3d\n", 1234);

	// printf("------------test6-------------\n");
	// ft_printf("ft: %3.10d\n", 1234);
	// printf("or: %3.10d\n", 1234);

	// printf("or: %,*.d", 5, 4);
	// printf("or: test7\n");
	// ft_printf("ft: %d\n", 0);
	// ft_printf("ft: a=%10d\nb=%d\n", 25, 123);
	// printf("or: a = %10.d\nb = %d\n", 25, 31);
	// ft_printf("ft: a = %20.d\nb = %d\n", 25, 31);
	// ft_printf("ft: hello %+-15.10d world\n", 123);
	// printf("or: hello %+-15.10d world\n", 123);
	// printf("--------test1.1----------\n");
	// printf("or: hiw are you? % -20.5d hmm?\nfine %-+15.5d\n", -321, 45);
	// ft_printf("ft: hiw are you? % -20.5d hmm?\nfine %-+15.5d\n", -321, 45);
	// printf("--------test2.1----------\n");
	// printf("or: hello %15.10d world\na = %+10.5d\n", 123, 45);
	// ft_printf("ft: hello %15.10d world\na = %+10.5d\n", 123, 45);
	// printf("--------test3.1----------\n");
	// printf("or: %+d\n", 0);
	// ft_printf("ft: %+d\n", 0);
	// ft_printf("ft: %#llx\n", -143);
	// printf("or: %#llx\n", -143);
	// ft_printf("ft: %#x\n", 0);
	// printf("or: %#.5x\n", 0);

	//!  tests for spec "d"

	// printf("------------test1-------------\n");
	// ft_printf("ft: %#.10d\n", 1234);
	// printf("or: %#.10d\n", 1234);

	// printf("------------test2-------------\n");
	// ft_printf("ft: %3###---.2d\n", 1234);
	// printf("or: %3###---.2d\n", 1234);

	// printf("------------test3-------------\n");
	// ft_printf("ft: %--+++--10.40d\n", 1234);
	// printf("or: %--+++--10.40d\n", 1234);

	// printf("------------test4-------------\n");
	// ft_printf("ft: %##....4..4lld\n", 1234);
	// printf("or: %##....4..4lld\n", 1234);

	// printf("------------test5-------------\n");
	// ft_printf("ft: %0d\n", 1234);
	// printf("or: %0d\n", 1234);

	// printf("------------test6-------------\n");
	// ft_printf("ft: %.0d\n", 1234);
	// printf("or: %.0d\n", 1234);

	// printf("------------test7-------------\n");
	// ft_printf("ft: %#010.10d\n", 1234);
	// printf("or: %#010.10d\n", 1234);

	// printf("------------test8-------------\n");
	// ft_printf("ft: %-10.10d\n", 1234);
	// printf("or: %-10.10d\n", 1234);

	// printf("------------test9-------------\n");
	// ft_printf("ft: %+++10.40d\n", 1234);
	// printf("or: %+++10.40d\n", 1234);

	// //!не обрабатывается @
	// printf("------------test10-------------\n");
	// ft_printf("ft: %;+..4..4hd\n", 1234);
	// printf("or: %;+..4..4hd\n", 1234);

	// printf("------------test11-------------\n");
	// ft_printf("ft: %020.10d\n", 1234);
	// printf("or: %020.10d\n", 1234);

	// printf("------------test12-------------\n");
	// ft_printf("ft: %0d\n", 0);
	// printf("or: %0d\n", 0);

	// printf("------------test13-------------\n");
	// ft_printf("ft: %+..4..4hd\n", 0);
	// printf("or: %+..4..4hd\n", 0);

	// printf("------------test14-------------\n");
	// ft_printf("ft: %020.0d\n", 0);
	// printf("or: %020.0d\n", 0);

	// printf("------------test15-------------\n");
	// ft_printf("ft: %0.d\n", 0);
	// printf("or: %0.d\n", 0);

	// printf("------------test16-------------\n");
	// ft_printf("ft: %0d\n", -1);
	// printf("or: %0d\n", -1);

	// printf("------------test17-------------\n");
	// ft_printf("ft: %;+..4..4hd\n", -1);
	// printf("or: %;+..4..4hd\n", -1);

	// printf("------------test18-------------\n");
	// ft_printf("ft: %020.0d\n", -1);
	// printf("or: %020.0d\n", -1);

	// printf("------------test19-------------\n");
	// ft_printf("ft: %0.d\n", -1);
	// printf("or: %0.d\n", -1);


	// printf("--------test4.1----------\n");
	// printf("or: %-+10.5d\n", 31);
	// ft_printf("ft: %-+10.5d\n", 31);

	// printf("--------test4.2----------\n");
	// printf("or: %-+5.10d\n", 31);
	// ft_printf("ft: %-+5.10d\n", 31);

	// printf("--------test4.3----------\n");
	// printf("or: %+10.5d\n", 31);
	// ft_printf("ft: %+10.5d\n", 31);

	// printf("--------test4.4----------\n");
	// printf("or: %+5.10d\n", 31);
	// ft_printf("ft: %+5.10d\n", 31);

	// printf("--------test4.5----------\n");
	// printf("or: %-+10.1dw\n", 31);
	// ft_printf("ft: %-+10.1dw\n", 31);

	// printf("--------test4.6----------\n");
	// printf("or: %+10.1dw\n", 31);
	// ft_printf("ft: %+10.1dw\n", 31);

	// printf("--------test4.7----------\n");
	// printf("or: % 5.10dw\n", 31);
	// ft_printf("ft: % 5.10dw\n", 31);

	// printf("--------test4.8----------\n");
	// printf("or: %02.dw\n", 31);
	// ft_printf("ft: %02.dw\n", 31);

	// printf("--------test4.8----------\n");
	// printf("or: % 10.dw\n", -31);
	// ft_printf("ft: % 10.dw\n", -31);

	// printf("--------test4.8----------\n");
	// printf("or: %+10.hdw\n", 31);
	// ft_printf("ft: %+10.hdw\n", 31);

	//!  tests for spec "x/X"

	// printf("------------test1-------------\n");
	// ft_printf("ft: |%020x|\n", 1234);
	// printf("or: |%020x|\n", 1234);

	// printf("------------test2-------------\n");
	// ft_printf("ft: |%#0.20x|\n", 1234);
	// printf("or: |%#0.20x|\n", 1234);

	// printf("------------test3-------------\n");
	// ft_printf("ft: |%0.0x|\n", 1234);
	// printf("or: |%0.0x|\n", 1234);

	// printf("------------test4-------------\n");
	// ft_printf("ft: |%20.4x|\n", 1234);
	// printf("or: |%20.4x|\n", 1234);

	// printf("------------test5-------------\n");
	// ft_printf("ft: |%4.5x|\n", 1234);
	// printf("or: |%4.5x|\n", 1234);

	// printf("------------test6-------------\n");
	// ft_printf("ft: |%-20x|\n", 1234);
	// printf("or: |%-20x|\n", 1234);

	// printf("------------test7-------------\n");
	// ft_printf("ft: |%0x|\n", 0);
	// printf("or: |%0x|\n", 0);

	// printf("------------test8-------------\n");
	// ft_printf("ft: |%#x|\n", 0);
	// printf("or: |%#x|\n", 0);

	// printf("------------test9-------------\n");
	// ft_printf("ft: |%.1x|\n", 0);
	// printf("or: |%.1x|\n", 0);

	printf("------------test10-------------\n");
	ft_printf("ft: |%03.0x|\n", 0);
	printf("or: |%03.0x|\n", 0);

	// printf("------------test11-------------\n");
	// ft_printf("ft: |%#5x|\n", 0);
	// printf("or: |%#5x|\n", 0);

	// printf("------------test12-------------\n");
	// ft_printf("ft: |%#-10x|\n", 0);
	// printf("or: |%#-10x|\n", 0);

	// printf("------------test13-------------\n");
	// ft_printf("ft: %+..4..4hd\n", 0);
	// printf("or: %+..4..4hd\n", 0);

	// printf("------------test14-------------\n");
	// ft_printf("ft: |%x|\n", 0);
	// printf("or: |%x|\n", 0);

	// printf("------------test15-------------\n");
	// ft_printf("ft: |%#x|\n", 0);
	// printf("or: |%#x|\n", 0);

	// printf("------------test16-------------\n");
	// ft_printf("ft: |%#-20.10x|\n", 0);
	// printf("or: |%#-20.10x|\n", 0);

	// printf("------------test17-------------\n");
	// ft_printf("ft: %;+..4..4hd\n", -1);
	// printf("or: %;+..4..4hd\n", -1);

	// printf("------------test18-------------\n");
	// ft_printf("ft: |%#.x|\n", 1234);
	// printf("or: |%#.x|\n", 1234);
}
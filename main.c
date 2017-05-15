/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:54:03 by gduron            #+#    #+#             */
/*   Updated: 2017/05/15 12:07:29 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int		main()
{
	printf("%s\n", "abc");
	ft_printf("%s\n", "this is a string");
	ft_printf("%s \n", "this is a string");    
	ft_printf("%s  \n", "this is a string");   
	ft_printf("this is a %s\n", "string");     
	ft_printf("%s is a string\n", "this");     
	ft_printf("Line Feed %s\n", "\n");         
	ft_printf("%10s is a string\n", "this");   
	ft_printf("%.2s is a string\n", "this");   
	ft_printf("%5.2s is a string\n", "this");  
	ft_printf("%10s is a string\n", "");       
	ft_printf("%.2s is a string\n", "");       
	ft_printf("%5.2s is a string\n", "");      
	ft_printf("%-10s is a string\n", "this");  
	ft_printf("%-.2s is a string\n", "this");  
	ft_printf("%-5.2s is a string\n", "this"); 
	ft_printf("%-10s is a string\n", "");      
	ft_printf("%-.2s is a string\n", "");      
	ft_printf("%-5.2s is a string\n", "");     
	ft_printf("%s %s\n", "this", "is");        
	ft_printf("%s %s %s\n", "this", "is", "a");
	ft_printf("%s %s %s %s\n", "this", "is", "a", "multi");
	ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	ft_printf("@moulitest: %s\n", NULL);
	ft_printf("%s %s\n", NULL, "string");
	return (0);
}
/*
 *49. FAIL ft_printf("%s", "abc");                       -> "abc"
 50. FAIL ft_printf("%s", "this is a string");          -> "this is a string"
 51. FAIL ft_printf("%s ", "this is a string");         -> "this is a string "
 52. FAIL ft_printf("%s  ", "this is a string");        -> "this is a string  "
 53. FAIL ft_printf("this is a %s", "string");          -> "this is a string"
 54. FAIL ft_printf("%s is a string", "this");          -> "this is a string"
 55. FAIL ft_printf("Line Feed %s", "\n");              -> "Line Feed \n"
 56. FAIL ft_printf("%10s is a string", "this");        -> "      this is a string"
 57. FAIL ft_printf("%.2s is a string", "this");        -> "th is a string"
 58. FAIL ft_printf("%5.2s is a string", "this");       -> "   th is a string"
 59. FAIL ft_printf("%10s is a string", "");            -> "           is a string"
 60. FAIL ft_printf("%.2s is a string", "");            -> " is a string"
 61. FAIL ft_printf("%5.2s is a string", "");           -> "      is a string"
 62. FAIL ft_printf("%-10s is a string", "this");       -> "this       is a string"
 63. FAIL ft_printf("%-.2s is a string", "this");       -> "th is a string"
 64. FAIL ft_printf("%-5.2s is a string", "this");      -> "th    is a string"
 65. FAIL ft_printf("%-10s is a string", "");           -> "           is a string"
 66. FAIL ft_printf("%-.2s is a string", "");           -> " is a string"
 67. FAIL ft_printf("%-5.2s is a string", "");          -> "      is a string"
 68. FAIL ft_printf("%s %s", "this", "is");             -> "this is"
 69. FAIL ft_printf("%s %s %s", "this", "is", "a");     -> "this is a"
 70. FAIL ft_printf("%s %s %s %s", "this", "is", "a", "multi"); -> "this is a multi"
 71. FAIL ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string"); -> "this is a multi string. gg!"
 72. FAIL ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string"); -> "thisisamultistring"
 73. FAIL ft_printf("@moulitest: %s", NULL);            -> "@moulitest: (null)@moulitest: "
 74.      ft_printf("%.2c", NULL);                      -> ""
 75. FAIL ft_printf("%s %s", NULL, string);             -> " string"
 */

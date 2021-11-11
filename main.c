/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:00:20 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/11 17:17:23 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

void	iter_str(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = 'x';
}

void	iter_stri(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = 'a' + i;
}

char	map_str(char c)
{
	if (c >= 'a' && c <= 'z')
		c = 'x';
	return (c);
}

char	map_stri(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = 'a' + i;
	return (c);
}


int	main(void)
{
	/* MEMSET TESTS */
	char	str1[] = "This is a_test!";
	char	str2[] = "This is a_test!";

	ft_memset(str1 + 3, '.', sizeof(char) * 5);
	memset(str2 + 3, '.', sizeof(char) * 5);
	printf("TEST 1: memset\nown: %s\nsys: %s\nown: %s\nsys: %s\n", str1, str2, (char *) ft_memset(str1 + 3, '.', sizeof(char) * 5), (char *) memset(str2 + 3, '.', sizeof(char) * 5));
	ft_memset(str1 + 5, 34, sizeof(char) * 2);
	memset(str2 + 5, 34, sizeof(char) * 2);
	printf("own: %s\nsys: %s\nown: %s\nsys: %s\n\n", str1, str2, (char*) ft_memset(str1 + 5, 34, sizeof(char) * 2), (char *) memset(str2 + 5, 34, sizeof(char) * 2));

	/* BZERO TESTS */
	ft_bzero(str1 + 8, sizeof(char) * 1);
	bzero(str2 + 8, sizeof(char) * 1);
	printf("TEST 2: bzero\nown: %s %s\nsys: %s %s\n", str1, str1 + 9, str2, str2 + 9);
	ft_bzero(str1 + 3, sizeof(char) * 2);
	bzero(str2 + 3, sizeof(char) * 2);
	printf("own: %s %s %s\nsys: %s %s %s\n\n", str1, str1 + 5, str1 + 9, str2, str2 + 5, str2 + 9);

	/* MEMCPY TESTS */
	const char	src1[] = "This is another test!";
	char		dest1[50];
	const char	src2[] = "This is another test!";
	char		dest2[50];

	printf("TEST 3: memcpy\nown: %s\n", (char *) ft_memcpy(dest1, src1, 12));
	printf("sys: %s\n", (char *) memcpy(dest2, src2, 12));
	printf("own: %s\nsys: %s\nThere should be no undefined behavior at the end of the string (end with \\0)\n\n", dest1, dest2);

	/* MEMCCPY TESTS */
	const char	src3[] = "This iso another test!";
	char		dest3[50];
	char		dest5[50];
	const char	src4[] = "This iso another test!";
	char		dest4[50];
	char		dest6[50];

	ft_memccpy(dest3, src3, 'o', 12);
	memccpy(dest4, src4, 'o', 12);
	ft_memccpy(dest5, src3, 'x', 12);
	memccpy(dest6, src4, 'x', 12);
	printf("TEST 4: memccpy\nown: %s\nsys: %s\nown: %s\nsys: %s\nThere should be no undefined behavior at the end of the string (end with \\0)\n\n", dest3, dest4, dest5, dest6);

	/* MEMMOVE TESTS */
	char	src5[50] = "Repeat!";
	char	src6[50] = "Repeat!";
	char	src7[50] = "Repeat!";

	ft_memmove((src5 + 2), src5, 7);
	memmove((src6 + 2), src6, 7);
	ft_memcpy((src7 + 2), src7, 7);
	printf("TEST 5: memmove\nown: %s\nsys: %s\nmemcpy (should override): %s\n", src5, src6, src7);
	ft_memmove(src5, (src5 + 2), 7);
	memmove(src6, (src6 + 2), 7);
	printf("own: %s\nsys: %s\nThere should be nothing after Repeat! (string should end with \\0)\n\n", src5, src6);

	/* MEMCHR TESTS */
	const char	s1[] = "This iso another test!";
	const char	s2[] = "This iso another test!";

	printf("TEST 6: memchr\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", (char *) ft_memchr(s1, 'o', 10), (char *) memchr(s2, 'o', 10), (char *) ft_memchr(s1, 'o', 5), (char *) memchr(s2, 'o', 5), s1, s2);

	/* MEMCMP TESTS */
	const char	s3[] = "Identical strings!";
	const char	s4[] = "Identical strings!";
	const char	s5[] = "Two random strings";
	const char	s6[] = "Two different strings";
	const char	s7[] = "134";
	const char	s8[] = "256";

	printf("TEST 7: memcmp\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_memcmp(s3, s4, 20), memcmp(s3, s4, 20), ft_memcmp(s5, s6, 20), memcmp(s5, s6, 20), ft_memcmp(s7, s8, 0), memcmp(s7, s8, 0));

	/* STRLEN TESTS */
	const char	s9[] = "Identical strings!";
	const char	s10[] = "Identical strings! jkldsfdlkgfjsldgjdslkgfjl";
	const char	s11[] = "";

	printf("TEST 8: strlen\nown: %lu\nsys: %lu\nown: %lu\nsys: %lu\nown: %lu\nsys: %lu\n\n", ft_strlen(s9), strlen(s9), ft_strlen(s10), strlen(s10), ft_strlen(s11), strlen(s11));

	/* STRDUP TESTS */
	const char	s11_1[] = "This is a test!";

	printf("TEST 9: strdup\nown: %s\nsys: %s\n\n", ft_strdup(s11_1), strdup(s11_1));

	/* STRCPY TESTS */
	const char	s12[] = "This is a test!";
	char		d1[50];
	char		d2[50];

	printf("TEST 10: strcpy\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strcpy(d1, s12), strcpy(d2, s12), d1, d2);

	/* STRNCPY TESTS */
	const char	s13[] = "This is a test!";
	char		d3[50] = "1234567890123456789012345678901234567890";
	char		d4[50] = "1234567890123456789012345678901234567890";
	char		d5[50] = "1234567890123456789012345678901234567890";
	char		d6[50] = "1234567890123456789012345678901234567890";

	printf("TEST 11: strncpy\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nDST should not be \\0 terminated if src is shorter than len\n\n", ft_strncpy(d3, s13, 3), strncpy(d4, s13, 3), ft_strncpy(d5, s13, 30), strncpy(d6, s13, 30), d3, d4, d5, d6, d5 + 30, d6 + 30, d5 + 29, d6 + 29);

	/* STRCAT TESTS */
	char		s14[50] = "Start: ";
	char		s14_1[50] = "Start: ";
	const char	s15[] = "This is a test!";

	printf("TEST 12: strcat\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strcat(s14, s15), strcat(s14_1, s15), s14, s14_1);

	/* STRNCAT TESTS */
	char		s16[50] = "Start: ";
	char		s16_1[50] = "Start: ";
	const char	s17[] = "This is a test!";

	printf("TEST 13: strncat\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strncat(s16, s17, 8), strncat(s16_1, s17, 8), s16, s16_1, ft_strncat(s16, s17, 30), strncat(s16_1, s17, 30), s16, s16_1);

	/* STRLCAT TESTS */
	char		s18[10] = "Start: ";
	char		s18_1[10] = "Start: ";
	const char	s19[] = "This is a test!";
	char		s20[0] = "";
	char		s21[0] = "";
	char		s22[3] = "ab";
	char		s23[3] = "ab";

	printf("TEST 14: strlcat\nown: %s\nsys: %s\nown: %lu\nsys: %lu\nown: %s\nsys: %s\nown: %lu\nsys: %lu\nown: %s\nsys: %s\nown: %lu\nsys: %lu\n\n", s18, s18_1, ft_strlcat(s18, s19, 10), strlcat(s18_1, s19, 10), s20, s21, ft_strlcat(s20, s19, 0), strlcat(s21, s19, 0), s22, s23, ft_strlcat(s22, s19, 3), strlcat(s23, s19, 3));
	
	/* STRCHR / STRRCHR TESTS */
	const char	s24[] = "This is another test!";
	const char	s25[] = "This is another test!";

	printf("TEST 15: strchr\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strchr(s24, 'i'), strchr(s25, 'i'), ft_strchr(s24, 'x'), strchr(s25, 'x'), s24, s25);
	printf("TEST 16: strrchr\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strrchr(s24, 'i'), strrchr(s25, 'i'), ft_strrchr(s24, 'x'), strrchr(s25, 'x'), s24, s25);

	/* STRSTR / STRNSTR TESTS */
	const char	s26[] = "This is another test!";
	const char	s27[] = " another ";
	const char	s28[] = " anotfher ";
	const char	s29[] = "";

	printf("TEST 17: strstr\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strstr(s26, s27), strstr(s26, s27), ft_strstr(s26, s28), strstr(s26, s28), ft_strstr(s26, s29), strstr(s26, s29));
	printf("TEST 18: strnstr\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\nown: %s\nsys: %s\n\n", ft_strnstr(s26, s27, 40), strnstr(s26, s27, 40), ft_strnstr(s26, s27, 10), strnstr(s26, s27, 10), ft_strnstr(s26, s28, 40), strnstr(s26, s28, 40), ft_strnstr(s26, s29, 5), strnstr(s26, s29, 5));

	/* STRCMP / STRNCMP TESTS */
	const char	s30[] = "This is a test!";
	const char	s31[] = "This i";
	const char	s32[] = "This is a test! ";
	const char	s33[] = "This is a test!";

	printf("TEST 19: strcmp\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_strcmp(s30, s31), strcmp(s30, s31), ft_strcmp(s30, s32), strcmp(s30, s32), ft_strcmp(s30, s33), strcmp(s30, s33));
	printf("TEST 20: strncmp\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_strncmp(s30, s31, 100), strncmp(s30, s31, 100), ft_strncmp(s30, s32, 50), strncmp(s30, s32, 50), ft_strncmp(s30, s33, 50), strncmp(s30, s33, 50), ft_strncmp(s30, s32, 5), strncmp(s30, s32, 5), ft_strncmp(s30, s33, 5), strncmp(s30, s33, 5));

	/* ATOI TESTS */
	const char	s34[] = "2147483648";
	const char	s35[] = "  f  -1234";
	const char	s36[] = "-+1234";
	const char	s37[] = "1 2    1234";
	const char	s38[] = "    -12kk34";
	const char	s39[] = "+1234kk";
	const char	s40[] = "    +1234";
	const char	s41[] = " \f \n \r \t \v  1234";

	printf("Test 21: atoi\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_atoi(s34), atoi(s34), ft_atoi(s35), atoi(s35), ft_atoi(s36), atoi(s36), ft_atoi(s37), atoi(s37), ft_atoi(s38), atoi(s38), ft_atoi(s39), atoi(s39), ft_atoi(s40), atoi(s40), ft_atoi(s41), atoi(s41));

	/* ISALPHA TESTS */
	printf("Test 22: isalpha\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_isalpha('?'), isalpha('?'), ft_isalpha('('), isalpha('('), ft_isalpha(80), isalpha(80), ft_isalpha('\v'), isalpha('\v'), ft_isalpha('Z'), isalpha('Z'), ft_isalpha(55), isalpha(55), ft_isalpha('0'), isalpha('0'), ft_isalpha('\n'), isalpha('\n'));
	printf("Test 23: isdigit\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_isdigit('x'), isdigit('x'), ft_isdigit(1), isdigit(1), ft_isdigit('?'), isdigit('?'), ft_isdigit('\0'), isdigit('\0'), ft_isdigit('a'), isdigit('a'), ft_isdigit(40), isdigit(40), ft_isdigit(57), isdigit(57), ft_isdigit('0'), isdigit('0'));
	printf("Test 24: isalnum\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_isalnum('X'), isalnum('X'), ft_isalnum(1), isalnum(1), ft_isalnum('?'), isalnum('?'), ft_isalnum('\0'), isalnum('\0'), ft_isalnum('a'), isalnum('a'), ft_isalnum(40), isalnum(40), ft_isalnum(57), isalnum(57), ft_isalnum('0'), isalnum('0'));
	printf("Test 25: isascii\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_isascii(0), isascii(0), ft_isascii(127), isascii(127), ft_isascii(-1), isascii(-1), ft_isascii(128), isascii(128), ft_isascii('\v'), isascii('\v'), ft_isascii('\0'), isascii('\0'));
	printf("Test 26: isprint\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\nown: %d\nsys: %d\n\n", ft_isprint(-1), isprint(-1), ft_isprint(31), isprint(31), ft_isprint(199), isprint(199), ft_isprint(32), isprint(32), ft_isprint(126), isprint(126), ft_isprint(127), isprint(127));
	printf("Test 27: toupper\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\n\n", ft_toupper(160), toupper(160), ft_toupper(0), toupper(0), ft_toupper(40), toupper(40), ft_toupper(50), toupper(50), ft_toupper(65), toupper(65), ft_toupper(75), toupper(75), ft_toupper(88), toupper(88), ft_toupper(97), toupper(97), ft_toupper(140), toupper(140), ft_toupper(122), toupper(122));
	printf("Test 28: tolower\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\nown: %c\nsys: %c\n\n", ft_tolower(160), tolower(160), ft_tolower(0), tolower(0), ft_tolower(40), tolower(40), ft_tolower(50), tolower(50), ft_tolower(65), tolower(65), ft_tolower(75), tolower(75), ft_tolower(88), tolower(88), ft_tolower(97), tolower(97), ft_tolower(140), tolower(140), ft_tolower(122), tolower(122));

	/* MEMALLOC TESTS */
	void	*s42 = ft_memalloc(10);
	char	*s43 = ft_memalloc(10);

	printf("TEST 29: memalloc\nshould be null: %s\nshould be null: %s\nshould be random: %s\nshould be null: %c\nshould be null: %c\nshould be random: %c\n", (char *) s42, (char *) (s42 + 9), (char *) (s42 + 10), *s43, *(s43 + 9), *(s43 + 10));
	int	i = -1;
	while (++i < 5)
		s43[i] = 'b';
	printf("should be bbbbb: %s\nshould be address: %p\nshould be address: %p\n\n", s43, s42, s43);
	
	/* MEMDEL TESTS */
	ft_memdel(&s42);
	ft_memdel((void *) &s43);
	printf("TEST 30: memdel\nshould be null: %s\nshould be null: %s\naddress should be gone: %p\naddress should be gone: %p\n\n", (char *) s42, s43, s42, s43);

	/* STRNEW TESTS */
	char	*s44 = ft_strnew(10);
	char	*s45 = ft_strnew(10);

	printf("TEST 31: strnew\nshould be null: %c\nshould be null: %c\nshould be random: %c\nshould be null: %c\nshould be null: %c\nshould be random: %c\n", *s44, *(s44 + 10), *(s44 + 11), *s45, *(s45 + 10), *(s45 + 11));
	i = -1;
	while (++i < 5)
		s45[i] = 'b';
	printf("should be bbbbb: %s\nshould be address: %p\nshould be address: %p\n\n", s45, s44, s45);
	
	/* STRDEL TESTS */
	ft_strdel(&s44);
	ft_strdel(&s45);
	printf("TEST 31: strdel\nshould be null: %s\nshould be null: %s\naddress should be gone: %p\naddress should be gone: %p\n\n", s44, s45, s44, s45);

	/* STRCLR TESTS */
	char 	s47[] = "asdjfgsogijslkjnfsdfj ";
	char	s46[] = "abcdefghijk";
	
	printf("TEST 32: strclr\nshould be abcdefghijk: %s\nshould be asdjfgsogijslkjnfsdfj : %s\n", s46, s47);
	ft_strclr(s46);
	ft_strclr(s47);
	printf("should be null: %c\nshould be null: %s\nshould be null: %s\n\n", s46[0], s46, s47);

	/* STRITER TESTS */
	char 	s48[] = "ogi jslk jnfs dfj ";
	char	s49[] = "abc4de3fg5hi!jk";
	
	ft_striter(s48, &iter_str);
	ft_striter(s49, &iter_str);
	printf("TEST 33: striter\nshould be xxx xxxx xxxx xxx : %s\nshould be xxx4xx3xx5xx!xx: %s\n\n", s48, s49);

	/* STRITER TESTS */
	char 	s50[] = "ogi jslk jnfs dfj ";
	char	s51[] = "ggg4ss3hh5ss!ff";
	
	ft_striteri(s50, &iter_stri);
	ft_striteri(s51, &iter_stri);
	printf("TEST 34: striteri\nshould be abc efgh jklm opq : %s\nshould be abc4ef3hi5kl!no: %s\n\n", s50, s51);

	/* STRMAP TESTS */
	const char 	s52[] = "ogi jslk jnfs dfj ";
	const char	s53[] = "ggg4ss3hh5ss!ff";
	char		*s54 = ft_strmap(s52, &map_str);
	char		*s55 = ft_strmap(s53, &map_str);

	printf("TEST 35: strmap\nshould be ogi jslk jnfs dfj : %s\nshould be ggg4ss3hh5ss!ff: %s\nshould be xxx xxxx xxxx xxx : %s\nshould be xxx4xx3xx5xx!xx: %s\nshould be address: %p\nshoulb be address: %p\n", s52, s53, s54, s55, s54, s55);
	ft_strdel(&s54);
	ft_strdel(&s55);
	printf("should be ogi jslk jnfs dfj : %s\nshould be ggg4ss3hh5ss!ff: %s\nshould be null: %s\nshould be null: %s\nno address: %p\nno address: %p\n\n", s52, s53, s54, s55, s54, s55);
	
	/* STRMAPI TESTS */
	const char 	s56[] = "ogi jslk jnfs dfj ";
	const char	s57[] = "ggg4ss3hh5ss!ff";
	char		*s58 = ft_strmapi(s56, &map_stri);
	char		*s59 = ft_strmapi(s57, &map_stri);

	printf("TEST 36: strmapi\nshould be ogi jslk jnfs dfj : %s\nshould be ggg4ss3hh5ss!ff: %s\nshould be abc efgh jklm opq : %s\nshould be abc4ef3hi5kl!no: %s\nshould be address: %p\nshoulb be address: %p\n", s56, s57, s58, s59, s58, s59);
	ft_strdel(&s58);
	ft_strdel(&s59);
	printf("should be ogi jslk jnfs dfj : %s\nshould be ggg4ss3hh5ss!ff: %s\nshould be null: %s\nshould be null: %s\nno address: %p\nno address: %p\n\n", s56, s57, s58, s59, s58, s59);

	/* STREQU / STRNEQU TESTS */
	const char 	s60[] = "Test is back!";
	const char	s61[] = "Test is back!";
	const char	s62[] = "Test is back! ";
	const char	s63[] = "Test is back";
	const char	s64[] = "";
	const char	s65[] = "";
	const char	s66[] = " Test is back!";

	printf("TEST 36: strequ\nshould be 1: %d\nshould be 0: %d\nshould be 0: %d\nshould be 0: %d\nshould be 0: %d\nshould be 1: %d\n\n", ft_strequ(s60, s61), ft_strequ(s60, s62), ft_strequ(s60, s63), ft_strequ(s60, s64), ft_strequ(s60, s66), ft_strequ(s64, s65));
	printf("TEST 37: strnequ\nshould be 1: %d\nshould be 1: %d\nshould be 0: %d\nshould be 0: %d\nshould be 0: %d\nshould be 1: %d\n\n", ft_strnequ(s60, s61, 30), ft_strnequ(s60, s62, 4), ft_strnequ(s60, s63, 40), ft_strnequ(s60, s64, 4), ft_strnequ(s60, s66, 4), ft_strnequ(s64, s65, 4));

	/* STRSUB TESTS */
	const char 	s67[] = "Test is back!";

	printf("TEST 38: strsub\nshould be t is back! (may be undefined unless strncpy is used): %s\nshould be t is: %s\nshould be undefined: %s\n\n", ft_strsub(s67, 3, 20), ft_strsub(s67, 3, 4), ft_strsub(s67, 200, 20));
	
	/* STRJOIN TESTS */
	const char 	s68[] = "Test is ";
	const char 	s69[] = "BACK!";
	const char 	s70[] = "";
	const char 	s71[] = "Test is back!";
	char		*s72;
	char		*s73;
	char		*s74;

	s72 = ft_strjoin(s68, s69);
	s73 = ft_strjoin(s70, s71);
	s74 = ft_strjoin(s59, s71);
	printf("TEST 39: strjoin\nshould be Test is BACK!: %s\nshould be Test is back!: %s\nshould be (null): %s\n", s72, s73, s74);
	ft_strdel(&s72);
	ft_strdel(&s74);
	ft_strdel(&s73);
	printf("should be (null): %s\nshould be (null): %s\nshould be (null): %s\nno address: %p\nno address: %p\nno address: %p\n\n", s72, s73, s74, s72, s73, s74);

	/* STRTRIM TESTS */
	const char 	s75[] = "  \n    \t This is a test!  \n  \t  ";
	const char 	s76[] = "This is a test!";
	char		*s77;
	char		*s78;

	s77 = ft_strtrim(s75);
	s78 = ft_strtrim(s76);
	printf("TEST 39: strjoin\nshould be This is a test!: %s\nshould be This is a test!: %s\n", s77, s78);
	ft_strdel(&s77);
	ft_strdel(&s78);
	printf("should be (null): %s\nshould be (null): %s\nno address: %p\nno address: %p\n\n", s77, s78, s77, s78);


	return (0);
}

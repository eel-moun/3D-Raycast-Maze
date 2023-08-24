/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:49:10 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 13:20:53 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef int		(*t_cmpfn)(void *, void *);

typedef void	(*t_delfn)(void *);

/* Counts the number of nodes in the linked list and returns it. */
int			ft_lstsize(t_list *lst);

/*
 * Creates a new `t_list` node, and returns a pointer to it
 * that can be freed using `free`.
 * The `next` member is set to NULL.
 * Returns NULL on allocation failure.
 */
t_list		*ft_lstnew(void *content);

/* Returns the last node of the linked list. */
t_list		*ft_lstlast(t_list *lst);

/* function li tatsorti lik wa5a hia matatsori lk walo hhh*/
t_list		*lst_put_orderly(t_list **lst, char *d_name);

/*
 * Adds the node `new` at the beginning of the linked list `*lst`.
 * If the linked list is empty, `*lst` is set to `new`.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/*
 * Adds the node `new` at the end of the linked list `*lst`.
 * If the linked list is empty, `*lst` is set to `new`.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/* Frees the node’s content using `del` then frees `lst` using `free()`. */
void		ft_lstdelone(t_list *lst, t_delfn fn);

/*
 * Frees the linked list's nodes and their contents using `ft_lstdelone()`
 * and sets `*lst` to NULL.
 */
void		ft_lstclear(t_list **lst, t_delfn fn);

/*
 * Calls `f` for each node in the linked list.
 * `f` receives a pointer to the content of the currently processed node.
 */
void		ft_lstiter(t_list *lst, void (*f)(void*));

/* Removes the provided node from the list `*lst` but does not free it. */
void		ft_lstremove(t_list **lst, t_list *to_rm);

/*
 * Calculates the length of the string `s`,
 * excluding the terminating NUL-byte.
 */
size_t		ft_strlen(const char *s);

/*
 * Copies up to `size - 1` characters
 * from the NUL-terminated string `src` to `dst`,
 * NUL-terminating the result.
 * Returns the length of `src`.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
 * Returns the number of bytes in the initial segment of `s`
 * which are not in the string `reject`.
 * The NUL-byte is not considered in the matching process.
 */
size_t		ft_strspn(const char *s, const char *charset);

/*
 * Compares at most `n` bytes from the two strings `s1` and `s2`.
 * It returns an integer less than, equal to, or greater than zero
 * if `s1` is found, respectively, to be less than, to match,
 * or be greater than s2.
 * If `n` is zero, the return value is zero.
 */
size_t		ft_strcspn(const char *s, const char *charset);

/*
 * Appends the string `src` to the end of `dst`, NUL-terminating the result.
 * Retruns the initial length of `dst` plus the length of `src`.
 * If `size` characters are traversed without finding a NUL-byte,
 * the length of `dst` is considered to be `size`,
 * and the result will not be NUL-terminated.
 */
int			ft_strlcat(char *dst, const char *src, int dstsize);

/*
 * Returns a pointer to the first occurrence of the character `c`
 * in the string `s` or NULL otherwise.
 * The terminating NUL-byte is considered part of the string.
 */
char		*ft_strchr(const char *s, int c);

/*
 * Returns the number of bytes in the initial segment of `s`
 * which consist only of bytes from `accept`.
 * The NUL-byte is not considered in the matching process.
 */
char		*ft_strrchr(const char *s, int c);

/*
 * Finds the first occurrence of the string `needle` in the string `haystack`.
 * Return a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* Same as `ft_strlen()` except that it counts at most `n` characters. */
int			ft_strnlen(const char *str, int n);

/*
 * Compares bytes from the two strings `s1` and `s2`.
 * It returns an integer less than, equal to, or greater than zero
 * if `s1` is found, respectively, to be less than, to match,
 * or be greater than s2.
 */
int			ft_strcmp(char *s1, char *s2);

/*
 * Compares at most `n` bytes from the two strings `s1` and `s2`.
 * It returns an integer less than, equal to, or greater than zero
 * if `s1` is found, respectively, to be less than, to match,
 * or be greater than s2.
 * If `n` is zero, the return value is zero.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * Checks for an alphabetic character.
 * It is equivalent to `(ft_isupper(c) || ft_islower(c))`.
 */
int			ft_isalpha(int c);

/* Checks for a digit character (0 through 9).*/
int			ft_isdigit(int c);

/*
 * Checks for an alphanumeric character.
 * It is equivalent to `(ft_isalpha(c) || ft_isdigit(c))`.
 */
int			ft_isalnum(int c);

/*
 * Checks whether `c` is a 7-bit unsigned char value
 * that fits into the ASCII character set.
 */
int			ft_isascii(int c);

/* Checks for any printable character including space. */
int			ft_isprint(int c);

/* Returns the uppercase equivalent of `c` or `c` itself if there's none. */
int			ft_toupper(int c);

/* Returns the lowercase equivalent of `c` or `c` itself if there's none. */
int			ft_tolower(int c);

/*
 * Converts the initial part of the string `str` to an int.
 * The string may begin with an arbitrary amount of white space
 * followed by a single optional '+' or '-' sign.
 * The remainder of the string is converted to an int in the obvious manner,
 * stopping at the first character which is not a valid digit.
 * If an overflow occurs, INT_MAX is returned and errno is set to ERANGE.
 * If an undeflow occurs, INT_MIN is returned and errno is set to ERANGE.
 */
int			ft_atoi(const char *str);

/*
 * Returns an integer less than, equal to, or greater than zero
 * if the first `n` bytes of `s1` are found, respectively,
 * to be less than, to match, or be greater than the first `n` bytes of `s2`.
 * The memory areas are interpreted as unsigned char.
 * If `n` is zero, the return value is zero.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * Allocates memory for an array of `count` elements of `size` bytes each
 * and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * If `count` or  `size` is 0,
 * then ft_calloc() returns either NULL,
 * or a unique pointer value that can later be successfully passed to free()
 * Integer overflow is not handled.
 */
void		*ft_memset(void *b, int c, size_t len);

/*
 * Copies `n` bytes from memory area `src` to memory area `dst`.
 * The memory areas must not overlap.
 * Returns `dst`.
 */
void		*ft_memcpy(void *dst, const void *src, size_t n);

/*
 * Copies `n` bytes from memory area `src` to memory area `dst`.
 * The memory areas may overlap.
 * Returns `dst`.
 */
void		*ft_memmove(void *dst, const void *src, size_t len);

/*
 * Scans the initial `n` bytes of the memory area
 * pointed to by `s` for the first instance of `c`.
 * Both `c` and the bytes of the memory area pointed to by `s`
 * are interpreted as unsigned char.
 * Returns a pointer to the matching byte or NULL otherwise.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/*
 * Copies `n` bytes from memory area `src` to memory area `dst`.
 * The memory areas must not overlap.
 * Returns `dst`.
 */
void		ft_bzero(void *s, size_t n);

/*
 * Erases the data in the `n` bytes of the memory
 * starting at the location pointed to by `s`,
 * by writing zeros to that area.
 */
void		*ft_calloc(size_t count, size_t size);

void		lst_put_orderly_sorted_2(t_list **lst, t_list *new);

void		lst_put_orderly_sorted(t_list **lst, t_list *new, t_cmpfn cmpfn);

/*
 * Returns a pointer to a new string which is a duplicate of the string `s`,
 * or NULL on allocation failure.
 */
char		*ft_strdup(const char *s1);

/*
 * Returns a pointer to a new string which is a substring of `s`
 * that starts at `start` and has a maximum length of `len`,
 * or NULL on allocation failure.
 * If `start` exceeds the length of `s`
 * then start is considered to be ft_strlen(s).
 */
char		*ft_substr(const char *s, unsigned int start, size_t len);

/*
 * Returns a pointer to a new string that is the result of concatenating
 * `s1` and `s2`, Or NULL on allocation failure.
 */
char		*ft_strjoin(const char *s1, const char *s2);

/*
 * Removes all leading and trailing occurrences
 * of characters in the string `set` from the string `s`,
 * and returns a pointer to a new string which contains the result,
 * or NULL on allocation failure.
 * The NUL-byte is not considered in the matching process.
 */
char		*ft_strtrim(char const *s1, char const *set);

/*
 * Splits `s` into an array of substrings.
 * The substrings are delimited by at least one occurence
 * of one of the characters in the `sep` set.
 * Returns a pointer to the array of substrings, or NULL on allocation failure.
 */
char		**ft_split(char const *s, char c);

/*
 * Converts an int to its string representation.
 * Returns NULL on allocation failure.
 */
char		*ft_itoa(int n);

/*
 * Returns a pointer to a new string populated with the results of calling `f`
 * on every character in `s`, or NULL on allocation failure.
 * `f` receives the index of the processed character
 * and the character itself.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
 * Locates, in the string referenced by `*str`,
 * the first occurrence of any character in the string `sep`
 * (or the terminating '\0' character) and replaces it with a '\0'.
 * The location of the next character after the delimiter character
 * (or NULL, if the end of the string was reached) is stored in `*str`.
 * The original value of `*str` is returned.
 * If `*str` is initially NULL, NULL is returned.
 */
char		*ft_strsep(char **str, const char *sep);

/*
 * Calls `f` on each character in `s`.
 * `f` receives the index of the processed character
 * and a pointer to it.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
 * Outputs the character `c` to the file descriptor `fd`.
 * Returns the number of bytes written or -1 on failure.
 */
void		ft_putchar_fd(char c, int fd);

/*
 * Outputs the string `s` to the file descriptor `fd`.
 * Returns the number of bytes written or -1 on failure.
 */
void		ft_putstr_fd(char *s, int fd);

/*
 * Outputs the string `s` to the file descriptor `fd`,  followed by a newline.
 * Returns the number of bytes written or -1 on failure.
 */
void		ft_putendl_fd(char *s, int fd);

/*
 * Outputs the string representation of an int to the file descriptor `fd`.
 * Returns the number of bytes written or -1 on failure.
 */
void		ft_putnbr_fd(int n, int fd);

/*
 * Converts the initial part of the string `str` to a long long.
 * The string may begin with an arbitrary amount of white space
 * followed by a single optional '+' or '-' sign.
 * The remainder of the string is converted to a long long
 * in the obvious manner,
 * stopping at the first character which is not a valid digit.
 * If an overflow occurs, LONG_LONG_MAX is returned and errno is set to ERANGE.
 * If an underflow occurs, LONG_LONG_MIN is returned and errno is set to ERANGE.
 */
long long	ft_atoll(const char *str);

/*It free 2D char table
 *It take table to be free and return void
 */
void		ft_free(char **s);

/*It calc the lenght of 2D char table
 *It take table to be calc and return lenght of it
 */
int			ft_2d_len(char **av);

/*
 * Returns a line read from the file descriptor `fd`.
 * Returns NULL if there are no more characters to read,
 * or if an error occured.
 */
char		*get_next_line(int fd);

#endif

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void *destination, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memcpy(void *destination, const void *source, size_t n);
void	*ft_memchr (const void *arr, int c, size_t n);
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memmove(void *destptr, const void *srcptr, size_t num);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *string, int symbol);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *string1, const char *string2, size_t num);
size_t	ft_strlcat (char *dst, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int c);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif //GITLIBFT_EX_LIBFT_H

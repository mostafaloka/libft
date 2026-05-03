<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>libft — C Standard Library · moelgham</title>
<link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:ital,wght@0,300;0,400;0,500;0,700;1,300&family=Syne:wght@400;700;800&display=swap" rel="stylesheet">
<style>
*, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }
:root {
  --bg:      #0b0d12;
  --bg2:     #10131a;
  --bg3:     #161922;
  --border:  #222636;
  --border2: #2d3248;
  --txt:     #b8bdd0;
  --txt2:    #7a8098;
  --head:    #e8ecf5;
  --green:   #34d47a;  --green-bg: #0a2218; --green-bd: #163a28;
  --blue:    #5b9cf6;  --blue-bg:  #0a1428; --blue-bd:  #142444;
  --amber:   #f5a623;  --amber-bg: #1e1204; --amber-bd: #362008;
  --coral:   #f06060;  --coral-bg: #200a0a; --coral-bd: #3a1010;
  --purple:  #a78bfa;  --purple-bg:#120a28; --purple-bd:#201048;
  --teal:    #2dd4bf;  --teal-bg:  #041614; --teal-bd:  #083028;
}
html { scroll-behavior: smooth; }
body {
  background: var(--bg);
  color: var(--txt);
  font-family: 'JetBrains Mono', monospace;
  font-size: 13.5px;
  line-height: 1.8;
  min-height: 100vh;
}
body::after {
  content:'';
  position:fixed; inset:0; pointer-events:none; z-index:999;
  background: repeating-linear-gradient(0deg, transparent, transparent 2px, rgba(0,0,0,0.025) 2px, rgba(0,0,0,0.025) 4px);
}
.wrap { max-width: 960px; margin: 0 auto; padding: 72px 36px 120px; }
.hero { margin-bottom: 80px; }
.ascii-art {
  font-size: 10.5px; line-height: 1.25; color: var(--green);
  text-shadow: 0 0 28px rgba(52,212,122,0.22);
  margin-bottom: 32px; overflow-x: auto; white-space: pre;
}
.hero-tagline {
  font-family: 'Syne', sans-serif; font-size: 13px; font-weight: 400;
  color: var(--txt2); letter-spacing: 0.14em; text-transform: uppercase; margin-bottom: 10px;
}
.hero-byline { font-size: 12px; color: var(--txt2); margin-bottom: 28px; font-style: italic; }
.hero-byline span { color: var(--green); font-style: normal; font-weight: 500; }
.pills { display:flex; flex-wrap:wrap; gap:8px; }
.pill {
  font-size: 11px; font-weight: 500; letter-spacing: 0.06em;
  padding: 4px 14px; border-radius: 20px; border: 1px solid; white-space: nowrap;
}
.pill-g { background:var(--green-bg);  color:var(--green);  border-color:var(--green-bd); }
.pill-b { background:var(--blue-bg);   color:var(--blue);   border-color:var(--blue-bd); }
.pill-a { background:var(--amber-bg);  color:var(--amber);  border-color:var(--amber-bd); }
.pill-p { background:var(--purple-bg); color:var(--purple); border-color:var(--purple-bd); }
.pill-c { background:var(--coral-bg);  color:var(--coral);  border-color:var(--coral-bd); }
.sec { margin-bottom: 72px; }
.sec-num { font-size: 10px; letter-spacing: 0.25em; text-transform: uppercase; color: var(--txt2); margin-bottom: 6px; }
h2 {
  font-family: 'Syne', sans-serif; font-size: 24px; font-weight: 800;
  color: var(--head); margin-bottom: 8px;
  display:flex; align-items:center; gap:10px;
}
.hl { flex:1; height:1px; background: linear-gradient(90deg, var(--border2), transparent); margin-left:8px; }
.sec-intro { color: var(--txt2); font-size: 13px; margin-bottom: 28px; max-width: 680px; }
h3 {
  font-family: 'Syne', sans-serif; font-size: 15px; font-weight: 700;
  color: var(--head); margin: 36px 0 14px;
  display: flex; align-items: center; gap: 10px;
}
h3::before { content:''; display:inline-block; width:3px; height:16px; background:var(--green); border-radius:2px; }
p { color:var(--txt); max-width:680px; margin-bottom:14px; }
.cards { display:grid; grid-template-columns:repeat(auto-fill, minmax(200px,1fr)); gap:14px; margin:20px 0; }
.card {
  background: var(--bg2); border:1px solid var(--border); border-radius:10px;
  padding:20px 18px; position:relative; overflow:hidden;
  transition: border-color .2s, transform .2s;
}
.card:hover { border-color:var(--border2); transform:translateY(-3px); }
.card-stripe { position:absolute; top:0; left:0; right:0; height:3px; border-radius:10px 10px 0 0; }
.card h4 { font-family:'Syne',sans-serif; font-size:13px; font-weight:700; color:var(--head); margin-bottom:6px; }
.card p { font-size:12px; color:var(--txt2); line-height:1.6; max-width:none; margin:0; }
.ftable { width:100%; border-collapse:collapse; margin:20px 0; border-radius:10px; overflow:hidden; border:1px solid var(--border); }
.ftable thead { background:var(--bg3); }
.ftable th { padding:10px 16px; font-size:10px; text-transform:uppercase; letter-spacing:0.18em; color:var(--txt2); text-align:left; border-bottom:1px solid var(--border); }
.ftable td { padding:11px 16px; border-bottom:1px solid var(--bg3); font-size:12.5px; vertical-align:top; }
.ftable tr:last-child td { border:none; }
.ftable tr:hover td { background:var(--bg3); }
.fn { color:var(--amber); font-weight:500; white-space:nowrap; }
.fd { color:var(--blue); font-size:11.5px; }
.fc { color:var(--txt2); font-size:12px; }
.ftree {
  background:var(--bg2); border:1px solid var(--border); border-radius:10px;
  padding:24px 28px; font-size:12.5px; line-height:2.2;
}
.fdir{color:var(--blue);} .ffile{color:var(--txt);} .fsep{color:var(--border2);}
.fmeta{color:var(--txt2);} .fhl{color:var(--green);font-weight:500;}
.cb {
  background:var(--bg2); border:1px solid var(--border); border-radius:8px;
  padding:18px 22px; margin:14px 0; font-size:13px; line-height:2; overflow-x:auto;
}
.pr{color:var(--green);user-select:none;}
.cm{color:var(--head);} .ca{color:var(--blue);} .co{color:var(--txt2);}
.term { background:var(--bg2); border:1px solid var(--border); border-radius:12px; overflow:hidden; margin:20px 0; }
.term-bar {
  background:var(--bg3); border-bottom:1px solid var(--border);
  padding:10px 16px; display:flex; align-items:center; gap:7px;
}
.tb { width:11px; height:11px; border-radius:50%; }
.tb-r{background:#f06060;} .tb-a{background:#f5a623;} .tb-g{background:#34d47a;}
.term-title { font-size:11px; color:var(--txt2); margin-left:6px; letter-spacing:0.08em; }
.term pre { padding:22px 26px; font-size:12px; line-height:2; overflow-x:auto; color:var(--txt); }
.g{color:var(--green);} .b{color:var(--blue);} .a{color:var(--amber);}
.c{color:var(--coral);} .p{color:var(--purple);} .t{color:var(--teal);}
.m{color:var(--txt2);} .w{color:var(--head);font-weight:500;}
.foot {
  margin-top:100px; padding-top:32px; border-top:1px solid var(--border);
  display:flex; justify-content:space-between; align-items:center; flex-wrap:wrap; gap:14px;
}
.foot-l { font-size:12px; color:var(--txt2); }
.foot-l strong { color:var(--green); }
.foot-r { font-size:11px; color:var(--txt2); letter-spacing:0.06em; }
@keyframes up { from{opacity:0;transform:translateY(16px)} to{opacity:1;transform:none} }
.hero{animation:up .5s ease both;}
.sec{animation:up .5s ease both;}
.sec:nth-child(2){animation-delay:.06s}
.sec:nth-child(3){animation-delay:.12s}
.sec:nth-child(4){animation-delay:.18s}
.sec:nth-child(5){animation-delay:.22s}
</style>
</head>
<body>
<div class="wrap">

<header class="hero">
<div class="ascii-art"> ██╗     ██╗██████╗ ███████╗████████╗
 ██║     ██║██╔══██╗██╔════╝╚══██╔══╝
 ██║     ██║██████╔╝█████╗     ██║
 ██║     ██║██╔══██╗██╔══╝     ██║
 ███████╗██║██████╔╝██║        ██║
 ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝</div>
<div class="hero-tagline">Custom C Standard Library &mdash; 42 School Project</div>
<div class="hero-byline"><em>Reimplementing the C standard library from scratch &mdash; by <span>moelgham</span>.</em></div>
<div class="pills">
  <span class="pill pill-g">C</span>
  <span class="pill pill-b">Makefile</span>
  <span class="pill pill-a">no external libs</span>
  <span class="pill pill-p">static library (.a)</span>
  <span class="pill pill-c">42 curriculum</span>
</div>
</header>

<!-- 01 -->
<section class="sec">
<div class="sec-num">01 &mdash; description</div>
<h2>What is this? <span class="hl"></span></h2>
<p class="sec-intro">The first real project at 42. You rewrite libc functions yourself — no shortcuts, no includes from &lt;string.h&gt; or &lt;stdlib.h&gt;.</p>
<p>The goal is simple: understand exactly what these functions do, byte by byte, character by character. You use this library in every single project that comes after it.</p>
<div class="cards" style="margin-top:28px;">
  <div class="card">
    <div class="card-stripe" style="background:var(--blue)"></div>
    <h4>Memory</h4>
    <p>memset, bzero, memcpy, memmove, memchr, memcmp, calloc</p>
  </div>
  <div class="card">
    <div class="card-stripe" style="background:var(--green)"></div>
    <h4>Strings</h4>
    <p>strlen, strlcpy, strlcat, strchr, strrchr, strncmp, strnstr, strdup, substr, strjoin, strtrim, split</p>
  </div>
  <div class="card">
    <div class="card-stripe" style="background:var(--purple)"></div>
    <h4>Characters</h4>
    <p>isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower</p>
  </div>
  <div class="card">
    <div class="card-stripe" style="background:var(--amber)"></div>
    <h4>Output &amp; conversion</h4>
    <p>atoi, itoa, strmapi, striteri, putchar_fd, putstr_fd, putendl_fd, putnbr_fd</p>
  </div>
</div>
</section>

<!-- 02 -->
<section class="sec">
<div class="sec-num">02 &mdash; functions</div>
<h2>Function list <span class="hl"></span></h2>
<p class="sec-intro">All mandatory functions — reimplemented from scratch with the ft_ prefix.</p>

<h3>Memory</h3>
<table class="ftable">
<thead><tr><th>function</th><th>prototype</th><th>description</th></tr></thead>
<tbody>
<tr><td class="fn">ft_memset</td><td class="fd">void *ft_memset(void *s, int c, size_t n)</td><td class="fc">Fill n bytes of memory with value c</td></tr>
<tr><td class="fn">ft_bzero</td><td class="fd">void ft_bzero(void *s, size_t n)</td><td class="fc">Set n bytes of memory to zero</td></tr>
<tr><td class="fn">ft_memcpy</td><td class="fd">void *ft_memcpy(void *dst, const void *src, size_t n)</td><td class="fc">Copy n bytes from src to dst</td></tr>
<tr><td class="fn">ft_memmove</td><td class="fd">void *ft_memmove(void *dst, const void *src, size_t n)</td><td class="fc">Copy n bytes safely — handles overlapping memory</td></tr>
<tr><td class="fn">ft_memchr</td><td class="fd">void *ft_memchr(const void *s, int c, size_t n)</td><td class="fc">Find first occurrence of byte c in first n bytes</td></tr>
<tr><td class="fn">ft_memcmp</td><td class="fd">int ft_memcmp(const void *s1, const void *s2, size_t n)</td><td class="fc">Compare n bytes of two memory areas</td></tr>
<tr><td class="fn">ft_calloc</td><td class="fd">void *ft_calloc(size_t count, size_t size)</td><td class="fc">Allocate and zero-initialize memory</td></tr>
</tbody>
</table>

<h3>Strings</h3>
<table class="ftable">
<thead><tr><th>function</th><th>prototype</th><th>description</th></tr></thead>
<tbody>
<tr><td class="fn">ft_strlen</td><td class="fd">size_t ft_strlen(const char *s)</td><td class="fc">Return the length of string s</td></tr>
<tr><td class="fn">ft_strlcpy</td><td class="fd">size_t ft_strlcpy(char *dst, const char *src, size_t size)</td><td class="fc">Copy string with size limit, always null-terminates</td></tr>
<tr><td class="fn">ft_strlcat</td><td class="fd">size_t ft_strlcat(char *dst, const char *src, size_t size)</td><td class="fc">Append string with size limit</td></tr>
<tr><td class="fn">ft_strchr</td><td class="fd">char *ft_strchr(const char *s, int c)</td><td class="fc">Find first occurrence of c in s</td></tr>
<tr><td class="fn">ft_strrchr</td><td class="fd">char *ft_strrchr(const char *s, int c)</td><td class="fc">Find last occurrence of c in s</td></tr>
<tr><td class="fn">ft_strncmp</td><td class="fd">int ft_strncmp(const char *s1, const char *s2, size_t n)</td><td class="fc">Compare up to n characters of two strings</td></tr>
<tr><td class="fn">ft_strnstr</td><td class="fd">char *ft_strnstr(const char *h, const char *n, size_t len)</td><td class="fc">Find substring in haystack within len bytes</td></tr>
<tr><td class="fn">ft_strdup</td><td class="fd">char *ft_strdup(const char *s)</td><td class="fc">Duplicate string s with malloc</td></tr>
<tr><td class="fn">ft_substr</td><td class="fd">char *ft_substr(const char *s, unsigned int start, size_t len)</td><td class="fc">Allocate substring from s starting at index start</td></tr>
<tr><td class="fn">ft_strjoin</td><td class="fd">char *ft_strjoin(const char *s1, const char *s2)</td><td class="fc">Concatenate two strings into a new allocation</td></tr>
<tr><td class="fn">ft_strtrim</td><td class="fd">char *ft_strtrim(const char *s1, const char *set)</td><td class="fc">Remove leading and trailing chars found in set</td></tr>
<tr><td class="fn">ft_split</td><td class="fd">char **ft_split(const char *s, char c)</td><td class="fc">Split string by delimiter c into a null-terminated array</td></tr>
<tr><td class="fn">ft_strmapi</td><td class="fd">char *ft_strmapi(const char *s, char (*f)(unsigned int, char))</td><td class="fc">Apply f to each char, return new string</td></tr>
<tr><td class="fn">ft_striteri</td><td class="fd">void ft_striteri(char *s, void (*f)(unsigned int, char*))</td><td class="fc">Apply f to each char of s in place</td></tr>
</tbody>
</table>

<h3>Characters</h3>
<table class="ftable">
<thead><tr><th>function</th><th>prototype</th><th>description</th></tr></thead>
<tbody>
<tr><td class="fn">ft_isalpha</td><td class="fd">int ft_isalpha(int c)</td><td class="fc">Is c an alphabetic character?</td></tr>
<tr><td class="fn">ft_isdigit</td><td class="fd">int ft_isdigit(int c)</td><td class="fc">Is c a decimal digit?</td></tr>
<tr><td class="fn">ft_isalnum</td><td class="fd">int ft_isalnum(int c)</td><td class="fc">Is c alphanumeric?</td></tr>
<tr><td class="fn">ft_isascii</td><td class="fd">int ft_isascii(int c)</td><td class="fc">Is c in the ASCII table (0–127)?</td></tr>
<tr><td class="fn">ft_isprint</td><td class="fd">int ft_isprint(int c)</td><td class="fc">Is c a printable character?</td></tr>
<tr><td class="fn">ft_toupper</td><td class="fd">int ft_toupper(int c)</td><td class="fc">Convert c to uppercase</td></tr>
<tr><td class="fn">ft_tolower</td><td class="fd">int ft_tolower(int c)</td><td class="fc">Convert c to lowercase</td></tr>
</tbody>
</table>

<h3>Conversion &amp; Output</h3>
<table class="ftable">
<thead><tr><th>function</th><th>prototype</th><th>description</th></tr></thead>
<tbody>
<tr><td class="fn">ft_atoi</td><td class="fd">int ft_atoi(const char *str)</td><td class="fc">Convert string to integer</td></tr>
<tr><td class="fn">ft_itoa</td><td class="fd">char *ft_itoa(int n)</td><td class="fc">Convert integer to allocated string</td></tr>
<tr><td class="fn">ft_putchar_fd</td><td class="fd">void ft_putchar_fd(char c, int fd)</td><td class="fc">Write character c to file descriptor fd</td></tr>
<tr><td class="fn">ft_putstr_fd</td><td class="fd">void ft_putstr_fd(char *s, int fd)</td><td class="fc">Write string s to file descriptor fd</td></tr>
<tr><td class="fn">ft_putendl_fd</td><td class="fd">void ft_putendl_fd(char *s, int fd)</td><td class="fc">Write string s + newline to file descriptor fd</td></tr>
<tr><td class="fn">ft_putnbr_fd</td><td class="fd">void ft_putnbr_fd(int n, int fd)</td><td class="fc">Write integer n to file descriptor fd</td></tr>
</tbody>
</table>
</section>

<!-- 03 -->
<section class="sec">
<div class="sec-num">03 &mdash; usage</div>
<h2>Getting started <span class="hl"></span></h2>
<p class="sec-intro">Clone, build, link. Three steps.</p>

<h3>Build</h3>
<div class="cb">
  <div><span class="pr">$</span> <span class="cm">git clone</span> <span class="ca">https://github.com/mostafaloka/libft.git</span></div>
  <div><span class="pr">$</span> <span class="cm">cd libft && make</span></div>
  <div><span class="co"># → libft.a is ready</span></div>
</div>

<h3>Link in your project</h3>
<div class="cb">
  <div><span class="pr">$</span> <span class="cm">gcc</span> <span class="ca">main.c -L. -lft -I.</span> <span class="co">-o myprogram</span></div>
</div>

<div class="term" style="margin-top:20px;">
  <div class="term-bar"><span class="tb tb-r"></span><span class="tb tb-a"></span><span class="tb tb-g"></span><span class="term-title">example.c</span></div>
  <pre>  <span class="m">#include "libft.h"</span>

  <span class="b">int</span> <span class="g">main</span>(<span class="b">void</span>)
  {
      <span class="b">char</span>  *s     = <span class="g">ft_strdup</span>(<span class="a">"hello, 42"</span>);
      <span class="b">char</span>  **words = <span class="g">ft_split</span>(s, <span class="a">','</span>);
      <span class="b">char</span>  *n     = <span class="g">ft_itoa</span>(42 * 2);

      <span class="g">ft_putendl_fd</span>(s, 1);       <span class="m">// → "hello, 42"</span>
      <span class="g">ft_putendl_fd</span>(words[0], 1); <span class="m">// → "hello"</span>
      <span class="g">ft_putendl_fd</span>(words[1], 1); <span class="m">// → " 42"</span>
      <span class="g">ft_putendl_fd</span>(n, 1);       <span class="m">// → "84"</span>
      <span class="b">return</span> (0);
  }</pre>
</div>

<h3>Makefile rules</h3>
<div class="cb">
  <div><span class="pr">$</span> <span class="cm">make</span>         <span class="co"># compile → libft.a</span></div>
  <div><span class="pr">$</span> <span class="cm">make clean</span>   <span class="co"># remove .o files</span></div>
  <div><span class="pr">$</span> <span class="cm">make fclean</span>  <span class="co"># remove .o files + libft.a</span></div>
  <div><span class="pr">$</span> <span class="cm">make re</span>      <span class="co"># full rebuild</span></div>
</div>
</section>

<!-- 04 -->
<section class="sec">
<div class="sec-num">04 &mdash; structure</div>
<h2>Code layout <span class="hl"></span></h2>
<p class="sec-intro">One file per function. Flat, clean, no surprises.</p>
<div class="ftree">
  <div><span class="fdir">libft/</span></div>
  <div><span class="fsep">│</span></div>
  <div><span class="fsep">├── </span><span class="fhl">libft.h</span>              <span class="fmeta">→  all prototypes + includes</span></div>
  <div><span class="fsep">├── </span><span class="fhl">Makefile</span>             <span class="fmeta">→  all, clean, fclean, re</span></div>
  <div><span class="fsep">│</span></div>
  <div><span class="fsep">├── </span><span class="ffile">ft_mem*.c</span>            <span class="fmeta">→  memset bzero memcpy memmove memchr memcmp calloc</span></div>
  <div><span class="fsep">├── </span><span class="ffile">ft_str*.c</span>            <span class="fmeta">→  strlen strlcpy strlcat strchr strrchr strncmp strnstr</span></div>
  <div><span class="fsep">│                        </span><span class="fmeta">   strdup substr strjoin strtrim split strmapi striteri</span></div>
  <div><span class="fsep">├── </span><span class="ffile">ft_is*.c</span>             <span class="fmeta">→  isalpha isdigit isalnum isascii isprint</span></div>
  <div><span class="fsep">├── </span><span class="ffile">ft_to*.c</span>             <span class="fmeta">→  toupper tolower atoi itoa</span></div>
  <div><span class="fsep">└── </span><span class="ffile">ft_put*.c</span>            <span class="fmeta">→  putchar_fd putstr_fd putendl_fd putnbr_fd</span></div>
</div>
</section>

<footer class="foot">
  <div class="foot-l">built at 42 by <strong>moelgham</strong><br><span style="font-size:11px;opacity:.55;">the foundation of everything that comes after</span></div>
  <div class="foot-r">C &nbsp;·&nbsp; static library &nbsp;·&nbsp; 42 cursus</div>
</footer>

</div>
</body>
</html>

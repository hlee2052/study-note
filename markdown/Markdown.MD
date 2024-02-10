# Markdown.MD Note

## Bold + italic
_Italitc_:  \_Word_

**bold**: \*\*Word**

**_Italic + bold_** : \*\*\_Word_\*\*

##Headers


# Header 1 : \# largest
## Header 2: \#\#word
###### Header 6: \###### smallest

- can italicize header
- can't bold header

## Links
[HyperLink](www.google.ca): \[HyperLink](www.google.ca): 
- can bold, italicize
- can link within header

###Reference Link
Here's [Hyperlink from var1][link variable1].

Here's [Hyperlink from var2][link variable2].

[link variable1]: www.github.com
[link variable2]: www.google.com

#####Snippet for above example  

Here's \[Hyperlink from var1][link variable1].

Here's \[Hyperlink from var2][link variable2].

\[link variable1]: www.github.com

\[link variable2]: www.google.com

## Images

![Image](https://github.com/favicon.ico).

\![Image]\(https://github.com/favicon.ico).

### Image tag

![The founding father][Image var1]

[Image var1]:https://github.com/favicon.ico

\!\[The founding father][Image var1]

\[Image var1]: https://github.com/favicon.ico

### Image resize
<img src="http://octodex.github.com/images/founding-father.jpg" width="122">

\<img src="http://octodex.github.com/images/founding-father.jpg" width="122">
- originally very big image

### Blockquotes

> for i in range(10):
>
> Database index

\> for i in range(10):

\>

\> Database index
- can have bold, image, italic, etc

### List
* itemA
    * subA
        * sub-subA
            * sub-sub-subA
- itemB
1. item1
2. item2

\- itemA : for each line need to indent and use * 
            
\- itemB

1\. item1

2\. item2

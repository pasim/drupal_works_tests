"Autoload .vimrc on saving
autocmd! bufwritepost .vimrc source %
"Miscleneous
filetype on
syntax on
set number
"tab space 2 - Drupal coding standarts
set ts=2
"Setting to max 30 tabs open in 1 session
set tabpagemax=30
"A bit of more drupal related
set expandtab
set shiftwidth=2
set autoindent
set smartindent
"End drupal
filetype plugin on
autocmd FileType php noremap <C-L> :!/Applications/MAMP/bin/php/php5.3.6/bin/php -l %<CR>
autocmd FileType phtml noremap <C-L> :!/Applications/MAMP/bin/php/php5.3.6/bin/php -l %<CR>
"Drupal related file staff
au BufRead,BufNewFile *.module set filetype=php
au BufRead,BufNewFile *.install set filetype=php
au BufRead,BufNewFile *.test set filetype=php
au BufRead,BufNewFile *.inc set filetype=php
au BufRead,BufNewFile *.profile set filetype=php
au BufRead,BufNewFile *.view set filetype=php
"phhtml files - nce way to embed php in html
au BufRead,BufNewFile *.phtml set filetype=php
"docblock comments are continued when a newline is inserted
set comments=sr:/*,mb:*,ex:*/
"Auto cmplete
autocmd FileType css set omnifunc=csscomplete#CompleteCSS
autocmd FileType php set omnifunc=phpcomplete#CompletePHP
autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
"End autocmplete
"onpen a new tab
:imap <C-t> <Esc>:tabnew<CR>i
:imap <C-s-n> <ESC>:tabnext<CR>i
:imap <C-s-p> <ESC>:tabprevious<CR>i
"Open a new tab and switch to it
:nmap <C-t> :tabnew<CR>i
:nmap <C-s-n> :tabnext<CR>i
:nmap <C-s-p> :tabprevious<CR>i
:map <C-t> :tabnew<CR>i
:map <C-s-n> :tabnext<CR>i
:map <C-s-p> :tabprevious<CR>i
"copy to clipboarc mac in visual mode, thanks to
"http://blog.drydevelopment.com/vim-pbcopy-on-os-x
"and http://vim.wikia.com/wiki/Mac_OS_X_clipboard_sharing
:vmap <C-c> :w !pbcopy<CR><CR>  

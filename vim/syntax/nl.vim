" Vim syntax file
" Language:	NewLang
" Maintainer:	Lucas Gabriel Sanchez <lk.sanchez@gmail.com>
" Last Change:	2014 Oct 21
"

" For version 5.x: Clear all syntax items.
" For version 6.x: Quit when a syntax file was already loaded.
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

" We need nocompatible mode.
" Original setting will be restored.
let s:cpo_save = &cpo
set cpo&vim

syn keyword nlSelf      self
syn keyword nlReturn    return
syn keyword nlTypeDef   type
syn keyword nlImport    import
syn keyword nlAbstract  abstract
syn keyword nlExtends   extends
syn keyword nlStatic    static
syn keyword nlPrimitive primitive

syn keyword nlNull  null
syn keyword nlTrue  true
syn keyword nlFalse false

syn match nlComment /#.*$/
syn match nlNumber  /[^0-9][0-9]+/hs=s+1
syn match nlType    /^[A-Z][a-zA-Z0-9]*/
syn match nlType    /[^A-Za-z0-9][A-Z][a-zA-Z0-9]*/hs=s+1
syn match nlString  /"[^"]*"/

if version >= 508 || !exists("did_nl_syn_inits")
  if version <= 508
    let did_nl_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  HiLink nlSelf       Keyword
  HiLink nlReturn     Keyword
  HiLink nlImport     Include
  HiLink nlTypeDef    Define
  HiLink nlExtends    Define
  HiLink nlStatic     Define
  HiLink nlAbstract   Define
  HiLink nlPrimitive  Define
  HiLink nlNull       Constant
  HiLink nlTrue       Constant
  HiLink nlFalse      Constant
  HiLink nlNumber     Constant
  HiLink nlComment    Comment
  HiLink nlType       Type
  HiLink nlString     String

  delcommand HiLink
endif

let b:current_syntax = "nl"

let &cpo = s:cpo_save
unlet s:cpo_save

" vim:set sw=2 sts=2 ts=2 et:

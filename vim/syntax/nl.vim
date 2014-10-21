" Vim syntax file
" Language:	NewLang
" Maintainer:	Lucas Gabriel Sanchez <lk.sanchez@gmail.com>
" Last Change:	2014 Oct 21
"

" For version 5.x: Clear all syntax items.
" For version 6.x: Quit when a syntax file was already loaded.
if version < 600
  syntax clear
" elseif exists("b:current_syntax")
"   finish
endif

" We need nocompatible mode.
" Original setting will be restored.
let s:cpo_save = &cpo
set cpo&vim

syn keyword nlSelf      self
syn keyword nlTypeDef   type
syn keyword nlImport    import
syn keyword nlInterface interface
syn keyword nlExtends   extends
syn keyword nlUsing     using
syn keyword nlAs        as
syn keyword nlStatic    static
syn keyword nlPrimitive primitive

syn match nlComment /#.*$/
syn match nlString  /'[^']*'/
syn match nlNumber  /[^0-9][0-9]+/hs=s+1
syn match nlType    /^[A-Z][a-zA-Z0-9]*/
syn match nlType    /[^A-Za-z0-9][A-Z][a-zA-Z0-9]*/hs=s+1

if version >= 508 || !exists("did_nl_syn_inits")
  if version <= 508
    let did_nl_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  HiLink nlComment    Comment
  HiLink nlNumber     Constant
  HiLink nlTrailSpace Error
  HiLink nlSpaceError Error
  HiLink nlSpaceError Error
  HiLink nlImport     Include
  HiLink nlType       Type
  HiLink nlString     String
  HiLink nlSelf       Keyword
  HiLink nlTypeDef    Keyword
  HiLink nlInterface  Keyword
  HiLink nlExtends    Keyword
  HiLink nlUsing      Keyword
  HiLink nlAs         Keyword
  HiLink nlStatic     Keyword
  HiLink nlPrimitive  Define

  delcommand HiLink
endif

let b:current_syntax = "nl"

let &cpo = s:cpo_save
unlet s:cpo_save

" vim:set sw=2 sts=2 ts=2 et:

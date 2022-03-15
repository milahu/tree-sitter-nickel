(comment) @comment

[
  "if" 
  "then"
  "else"
  "let"
  ;"inherit"
  "in"
  ;"rec"
  ;"with" 
  ;"assert" 
] @keyword

((Id) @variable.builtin
  ;(#match? @variable.builtin "^(__currentSystem|__currentTime|__nixPath|__nixVersion|__storeDir|builtins|false|null|true)$")
  (#match? @variable.builtin "^(false|true)$")
(#is-not? local))

((Id) @function.builtin
  ; TODO command to generate this string
  ;(#match? @function.builtin "^(__add|__addErrorContext|__all|__any|__appendContext|__attrNames|__attrValues|__bitAnd|__bitOr|__bitXor|__catAttrs|__compareVersions|__concatLists|__concatMap|__concatStringsSep|__deepSeq|__div|__elem|__elemAt|__fetchurl|__filter|__filterSource|__findFile|__foldl'|__fromJSON|__functionArgs|__genList|__genericClosure|__getAttr|__getContext|__getEnv|__hasAttr|__hasContext|__hashFile|__hashString|__head|__intersectAttrs|__isAttrs|__isBool|__isFloat|__isFunction|__isInt|__isList|__isPath|__isString|__langVersion|__length|__lessThan|__listToAttrs|__mapAttrs|__match|__mul|__parseDrvName|__partition|__path|__pathExists|__readDir|__readFile|__replaceStrings|__seq|__sort|__split|__splitVersion|__storePath|__stringLength|__sub|__substring|__tail|__toFile|__toJSON|__toPath|__toXML|__trace|__tryEval|__typeOf|__unsafeDiscardOutputDependency|__unsafeDiscardStringContext|__unsafeGetAttrPos|__valueSize|abort|baseNameOf|derivation|derivationStrict|dirOf|fetchGit|fetchMercurial|fetchTarball|fromTOML|import|isNull|map|placeholder|removeAttrs|scopedImport|throw|toString)$")
  (#match? @function.builtin "^(import)$")
  (#is-not? local))

[
  (StrChunks)
  (StrBlockChunks)
] @string

;[
;  (path)
;  (hpath)
;  (spath)
;] @string.special.path

;(uri) @string.special.uri

[
  ;(integer)
  ;(float)
  (Num)
] @number

(RichTerm
  "%{" @punctuation.special
  "}" @punctuation.special) @embedded

; TODO
; (escape_sequence) @escape

(function
  universal: (Id) @variable.parameter
)

;(formal
;  name: (Id) @variable.parameter
;  "?"? @punctuation.delimiter)

(App
  function: [
    (Id) @function
    (select
      attrpath: (attrpath
        attr: (attr_identifier) @function .))])


(UnaryOp
  operator: _ @operator)

(BinaryOp
  operator: _ @operator)

(attr_identifier) @property

;(inherit attrs: (attrs_inherited (Id) @property) )

[
  ;";" ; not used in nickel?
  "."
  ","
] @punctuation.delimiter

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

(Id) @variable

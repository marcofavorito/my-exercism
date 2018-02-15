// Package bob should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package bob

import s "strings"
import "unicode"

var TO_QUESTION = "Sure."
var TO_YELL = "Whoa, chill out!"
var TO_YELLED_QUESTION = "Calm down, I know what I'm doing!"
var CALL = "Fine. Be that way!"
var WHATEVER = "Whatever."

var QUESTION_MARK = "?"
var CUTSET = "\t\r\n "

func isQuestion(str string) bool {
	return s.HasSuffix(str, QUESTION_MARK)
}

func isYelled(str string) bool {
	return s.ToUpper(str) == str && hasCharacters(str)
}

func hasCharacters(str string) bool {
	for _, c := range str {
		if unicode.IsLetter(c) {
			return true
		}
	}
	return false
}

func Hey(remark string) string {
	trimmed_remark := s.TrimRight(s.TrimLeft(remark, CUTSET), CUTSET)
	if isQuestion(trimmed_remark) {
		if isYelled(trimmed_remark) {
			return TO_YELLED_QUESTION
		} else {
			return TO_QUESTION
		}
	}
	if isYelled(trimmed_remark) {
		return TO_YELL
	}

	if trimmed_remark == "" {
		return CALL
	} else {
		return WHATEVER
	}

	return ""
}

//Utiliies for acronyms
package acronym

import "regexp"
import "strings"

//Compute the acronym of a string.
func Abbreviate(s string) string {

	reg, _ := regexp.Compile("[^a-zA-z0-9]+")
	new_s := reg.ReplaceAllString(s, " ")
	words := strings.Split(new_s, " ")
	res := ""
	for _, word := range words {
		res += strings.ToUpper(string(word[0]))
	}
	return res
}

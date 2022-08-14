package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	s := make([]int, n)
	cnt := make(map[int]int)
	for i := range s {
		fmt.Scan(&s[i])
		cnt[s[i]]++
	}

	niceCnt := 0
	value3 := -1
	for k, v := range cnt {
		if v == 1 {
			niceCnt++
		}
		if v >= 3 {
			value3 = k
		}
	}

	aSet := make(map[int]struct{})
	if niceCnt%2 == 1 {
		if value3 == -1 {
			fmt.Println("NO")
			return
		}
		aSet[value3] = struct{}{}
	}

	desired := (niceCnt + 1) / 2
	for k, v := range cnt {
		if v == 1 && len(aSet) < desired {
			aSet[k] = struct{}{}
		}
	}

	fmt.Println("YES")
	for _, si := range s {
		if _, ok := aSet[si]; ok {
			delete(aSet, si)
			fmt.Print("A")
		} else {
			fmt.Print("B")
		}
	}
	fmt.Println()
}

package main

import "fmt"

type elem struct {
	c   byte
	cnt int
}

func insert(buf []byte, c byte, cnt int) []byte {
	for i := 0; i < cnt; i++ {
		buf = append(buf, c)
	}
	return buf
}

func solve() {
	var s string
	fmt.Scan(&s)

	cur := elem{
		c:   s[0],
		cnt: 1,
	}
	var seq []elem
	for i := 1; i < len(s); i++ {
		if cur.c != s[i] {
			seq = append(seq, cur)
			cur = elem{
				c:   s[i],
				cnt: 1,
			}
			continue
		}
		cur.cnt++
	}
	seq = append(seq, cur)

	var result []byte
	for i := 0; i < len(seq)-1; i++ {
		result = insert(result, seq[i].c, seq[i].cnt)
		if seq[i].c < seq[i+1].c {
			result = insert(result, seq[i].c, seq[i].cnt)
		}
	}
	result = insert(result, seq[len(seq)-1].c, seq[len(seq)-1].cnt)

	fmt.Println(string(result))
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		fmt.Printf("Case #%d: ", i+1)
		solve()
	}
}

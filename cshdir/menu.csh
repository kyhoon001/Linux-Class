echo "manual menu"
set stop=0
while($stop == 0)
        cat<<MENU
        d: date time
        l: directory context
        w: user
        q: quit
MENU
        echo -n '?'
        set reply=$<
        switch ($reply)
                case "d" :
                 date
                 breaksw
                case "l":
                 ls
                 breaksw
                case "w":
                 who
                 breaksw
		case "q"
		 set stop = 1
		 breaksw
                default:
                 echo "wrong choice"
		endsw
end

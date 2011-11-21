#!/bin/sh

#
# 2
#

menu_choice=""
current_cd=""
title_file="title.cdb"
	track_file="tracks.cdb"

temp_file=/tmp/cdb.$$
trap 'rm -f $temp_file' EXIT 

#
# 3
#

get_return() {
	echo -e "Press return \c"
	read x
	return 0
}

get_confirm() {
	echo -e "Are you sure? \c"
	while true
	do
		read x
		case "$x" in
			y | yes | Y | Yes | YES )
				return 0;;
			n | no | N | No | NO )
				echo
				echo "Cancelled"
				return 1;;
			*) echo "Please enter yes or no";;
			esac
	done
}

#
# 4
#

set_menu_choice() {
	clear
	echo "Options :-"
	echo
	echo " a) Add new CD"
	echo " f) Find CD"
	echo " c) Count the CDs and tracks in the catalog"
	if [ "$cdcatnum" != "" ]; then
		echo " l) List tracks on $cdtitle"
		echo " r) iRemove $cdtitle"
		echo " u) Update track information for $cdtitle"
	fi
	echo " q)Quit"
	echo
	echo -e "Please enter choice then press return \c"
	read menu_choice
	return
}

#
# 5
#

insert_title() {
	echo $* >> $title_file
	return
}

insert_track() {
	echo $* >> $tracks_file
	return
}

add_record_tracks() {
	echo "Enter track information for this CD"
	echo "When no more tracks enter q"
	cdtrack=1
	while [ "$cdtitle" != "q" ]
	do
		echo -e "Track $cdtrack, track title? \c"
		read tmp
		cdtitle=${tmp%%,*}
		if [ "$tmp" != "$cdttitle" ]; then
			echo "Sorry, no commas allowed"
			continue
		fi
		if [ -n "$cdttitle" ]; then
			if [ "$cdttitle" != "q" ]; then
				insert_track $cdcatnum, $cdtrack, $cdttitle
			fi

			else
				cdtrack=$((cdtrack-1))
		fi
	cdtrack=$((cdtrack+1))
	done
}

#
# 6
#

add_records() {
# 초기 정보를 요구한다.
	echo -e "Enter catalog name \c"
		read tmp
		cdcatnum=${tmp%%,*}

	echo -e "Enter title \c"
	read tmp
	cdtitle=${tmp%%,*}

	echo -e "Enter type \c"
	read tmp
	cdtype=${tmp%%,*}

	echo -e "Enter artist/composer \c"
	read tmp
	cdac=${tmp%%,*}

# 정보를 입력하기 원하는지 확인한다.

	echo About to add new entry
	echo "$cdcatnum $cdtitle $cdtype $cdac"

# 확인하고 나면 타이플 파일에 추가한다.

if get_confirm; then
	insert_title $cdcatnum,$cdtile,$cdtype,$cdac
	add_record_tracks
else
	remove_records
fi

return
}

#
# 7
#

find_cd() {
	if [ "$1" = "n" ]; then
		asklist=n
	else
		asklist=y
	fi
	cdcatnum=""
	echo -e "Enter a string to search for in the CD titles \c"
	read searchstr
	if [ "$searchstr" = "" ]; then
		return 0
	fi
	grep "$searchstr" $title_file > %temp_file

	set $(wc -l $temp_file)
	linesfound=$l

	case "$linesfound" in
	0)	echo "Sorry, nothing found"
		get_return
		return 0
	;;
	1)	;;
	2)	echo "Sorry, not unique."
		echo "Found the following"
		cat $temp_file
		get_return
		return 0
	esac

	IFS=","
	read cdcatnum cdtitle cdtype cdac < $temp_file
	IFS=" "

	if [ -z "$cdcatnum" ]; then
		echo "Sorry, could not extract catalog field from $temp_file"
			get_return
		return 0
	fi

	echo
	echo Catalog number: $cdcatnum
	echo Title: $cdtitle
	echo Type: $cdtype
	echo Artist/Composer: $cdac
	echo
	get_return

	if [ "$asklist" = "y" ]; then
		echo -e "View tracks for this CD? \c"
			read x
		if [ "$x" = "y" ]; then
			echo
			list_tracks
			echo
		fi
	fi
	retrun 1
}

#
# 8
#

update_cd() {
	if [ -z "$cdcatnum" ]; then
		echo "You must select a CD first"
	find_cd n
	fi
	if [ -n "$cdcatnum" ]; then
		echo "Current tracks are :-"
		list_tracks
		echo
		echo "This will re-enter the tracks for $cdtitle"
		get_confirm && {
			grep -v "^${cdcatnum}, " $tracks_file > $temp_file
			mv $temp_file $tracks_file
			echo
			add_record_tracks
		}
	fi
	return
}

#
# 9
#

count_cds() {
	set $(wc -l $title_file)
	num_titles=$l
	set $(wc -l $tracks_file)
	num_tracks=$l
	echo found $num_titles CDs, with a total of $num_tracks tracks
	get_return
	return
}

#
# 10
#

remove_records() {
	if [ -z "$cdcatnum" ]; then
		echo "You are 
}

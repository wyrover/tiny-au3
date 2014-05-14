$res = 0
$sString = ""

if $sString > 0 then
    $res = 1
elseif $sString < 0 then
    $res = 2
else
    if $res == 0 then
        $res = 3
    endif
endif

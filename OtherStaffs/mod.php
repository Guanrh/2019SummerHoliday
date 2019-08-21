<?php
$result = apache_get_modules();
if(in_array('mod_rewrite', $result)) {
echo '支持';
} else {
echo '不支持';
}
?>
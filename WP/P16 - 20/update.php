<?php 
 
include_once 'db.php';
$first = $_POST['firstname'];
$last = $_POST['lastname'];
$mb = $_POST['mobile'];
$sql = "UPDATE users SET firstname = '$first',lastname = '$last' WHERE mobile = $mb ";
 
$query = mysqli_query($conn,$sql);
if(!$query)
{
    echo "Query does not work.".mysqli_error($conn);die;
}
else
{
    echo "Data successfully updated";
}
?>
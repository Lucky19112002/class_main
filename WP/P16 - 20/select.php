<?php 
include_once 'db.php';
 
$sql = "SELECT * FROM users";
 
$query = mysqli_query($conn,$sql);
 
if(!$query)
{
    echo "Query does not work.".mysqli_error($conn);die;
}
 
while($data = mysqli_fetch_array($query))
{
    echo "Firstname = ".$data['firstname']."<br>";
    echo "Lastname = ".$data['lastname']."<br>";
    echo "Mobile = ".$data['mobile']."<br><hr>";
}
?>
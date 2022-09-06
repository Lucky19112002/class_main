<?php
include_once 'db.php';
   $first = $_POST['firstname'];
   $last = $_POST['lastname'];
   $mobile = $_POST['mobile'];
   $sql = "INSERT INTO users (firstname,lastname,mobile) VALUES ('$first','$last','$mobile')";
   if (mysqli_query($conn, $sql)) {
      echo "New record has been added successfully !";
   }
   else {
      echo "Error: " . $sql . ":-" . mysqli_error($conn);
   }
   mysqli_close($conn);
?>
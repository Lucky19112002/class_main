<?php
    include_once 'db.php';
 
    $sql = "DELETE FROM users WHERE mobile='" . $_POST["mobile"] . "'";
 
    if (mysqli_query($conn, $sql)) {
 
        echo "Record deleted successfully";
 
    } else {
     
        echo "Error deleting record: " . mysqli_error($conn);
    }
    mysqli_close($conn);
?>
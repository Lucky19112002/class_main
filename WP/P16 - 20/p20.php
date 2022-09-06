<html>
    <head>
        <style>
        div 
        {
        	align:center;
        	width:170px;
        	height:250px;
            border: double black;
            border-radius: 5px;
            background-color: coral;
            padding: 20px;
        }
        </style>
    </head>
    <body>
        <div>
        <form  method="post">
            First_Name:<br/>
            <input type="text" name="firstname"/><br />
            Last_Name:<br/>
            <input type="text" name="lastname"/><br />
            Mobile_number:<br />
            <input type="text" name="mobile"/>
            <br><br>
            <input type="submit" value="Insert" onclick="javascript:form.action='/PRaticel/insert.php';">
            <br>
            <input type="submit" value="Delete" onclick="javascript:form.action='/PRaticel/delete.php';">
            <br>
            <input type="submit" value="Show all data" onclick="javascript:form.action='/PRaticel/select.php';">
            <br>
            <input type="submit" value="Update" onclick="javascript:form.action='/PRaticel/update.php';">
            <br>
        </form>
    </div>
    </body>

</html>
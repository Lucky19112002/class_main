// Java Program to Open Input URL in
// System Default Browser in Windows
/*{
import java.awt.Desktop;
import java.io.*;
import java.net.URI;

class network {
	public static void main(String[] args)
			throws Exception
	{
		Desktop desk = Desktop.getDesktop();
		
		// now we enter our URL that we want to open in our
		// default browser
		desk.browse(new URI("http://xyz.com"));
	}
}
}*/
import java.net.InetAddress;
import java.net.UnknownHostException;

class network {
	public static void main(String[] args)
	{
		String name ="";
		try{
			System.out.println("Host NAme / Numric Address : "+InetAddress.getLocalHost());
			InetAddress ip = InetAddress.getByName(name);
			System.out.println("Host Defaule Name : "+ ip);
			System.out.println("Host IP Address: "+ ip.getHostAddress());
			System.out.println("Host Default Name: "+ ip.getHostName());
		}
		catch(UnknownHostException e)
		{
			System.out.println("No find the IP-Address for :"+ name);
		}
	}
}
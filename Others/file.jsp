<html>
    <head> <title> DataBase </title> </head>
    <body> 
        <%@ page import="java.sql.*" %>
        <% 
            try{
 		Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/db", "root", "80019");
            Statement stmt = con.createStatement();
            ResultSet rs1 = stmt.executeQuery("select * from emp");
             while (rs1.next())
                out.println(rs1.getInt(1) + " " + rs1.getString(2) + " " + rs1.getString(3)+"\n");

             con.close();
            }
            catch(Exception e){
                out.println(e);
            }
        %>

    </body>
</html>
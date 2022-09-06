<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform" >

<xsl:template match="/">
<html>
    <body>
        <h2> CD Catalog</h2>
        <table border="1">
            <tr bgcolor="green">
                <th>Title</th>
                <th>Artist</th>
                <th>Company</th>
                <th>Price</th>
                <th>Year</th>
            </tr>
            <xsl:for-each select="cdcatalog/cd">
            <tr bgcolor="yellow">
                <td><xsl:value-of select="Title"/></td>
                <td><xsl:value-of select="Artist"/></td>
                <td><xsl:value-of select="Company"/></td>
                <td><xsl:value-of select="Price"/></td>
                <td><xsl:value-of select="Year"/></td>
            </tr>
            </xsl:for-each>            
        </table>
    </body>
</html>
</xsl:template>
</xsl:stylesheet>
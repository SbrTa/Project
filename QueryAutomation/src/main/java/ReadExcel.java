import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellType;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.*;

import static org.apache.poi.ss.usermodel.CellType.BLANK;

/**
 * @author SbrTa
 * @since 6/23/21  6:24 PM
 */

public class ReadExcel {
    public static void main(String args[]) throws IOException {
        FileInputStream fis = new FileInputStream(new File("/home/sbrta/Desktop/data.xlsx"));
        XSSFWorkbook wb = new XSSFWorkbook(fis);
        XSSFSheet sheet = wb.getSheetAt(0);

        File fout = new File("/home/bs589/Desktop/query.txt");
        FileOutputStream fos = new FileOutputStream(fout);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
        boolean skippedHeader = false;
        for (Row row : sheet)
        {
            if (!skippedHeader) {
                skippedHeader = true;
                continue;
            }
            Cell textCell = row.getCell(0);
            Cell phraseCell = row.getCell(1);
            if (textCell.getCellType() == CellType._NONE || textCell.getCellType() == BLANK
                    || phraseCell.getCellType() == CellType._NONE || phraseCell.getCellType() == BLANK) {
                continue;
            }
            String text = textCell.getStringCellValue();
            String phrase = phraseCell.getStringCellValue();

            text = text.trim().toLowerCase();
            phrase = phrase.trim().toLowerCase();
            phrase = phrase.replace("'","\\'");

            String query = "INSERT INTO word (articulation_type, allow_recognition, TEXT, alternative_text, related_word, LEVEL, target_sound, alternative_target_sound, target_sound_position, " +
                    "age_of_acquisition, place_of_production, manner_of_production, voicing, guid, is_active, created_by, modified_by) " +
                    "SELECT 3, 0, '" + phrase + "', alternative_text, word_id, LEVEL, target_sound, alternative_target_sound, target_sound_position, " +
                    "age_of_acquisition, place_of_production, manner_of_production, voicing, UUID(), 1, 131, 131 FROM word WHERE TEXT = '" + text + "' LIMIT 1;";

            bw.write(query);
            bw.newLine();
            bw.newLine();
            System.out.println(query);
        }
        bw.close();

    }
}
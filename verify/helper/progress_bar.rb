# source: https://gist.github.com/horyu/a6f36fc535d272b72a1f8fd01a543e62

# 資料
# エスケープ: http://7ujm.net/etc/esc.html
# エスケープ: https://www.mm2d.net/main/prog/c/console-02.html

class ProcessPrinter
  def initialize(diff)
    @move_start = "\033[#{diff}F" # 上移動 && 行頭移動
    @move_finish = "\033[#{diff}E" # 下移動 && 行頭移動
    @clear_line = "\033[2K"       # 行クリア
  end

  def pri(str)
    print [@move_start, @clear_line, str, @move_finish].join
  end
end

class ProcessPrinterGenerator
  def initialize(line_num)
    print "\n" * line_num
    @waiting_pos = line_num + 1
  end

  def gen(line_num)
    raise "invalid line_num" unless (1...@waiting_pos).cover?(line_num)
    ProcessPrinter.new(@waiting_pos - line_num)
  end
end
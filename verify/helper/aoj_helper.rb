# frozen_string_literal: true

require 'net/http'
require 'uri'
require 'json'
require './verify/helper/progress_bar.rb'

#
# AOJ Helper
#   AOJ API reference: http://developers.u-aizu.ac.jp/index
#
module AOJHelper
  @endpoint = 'https://judgedat.u-aizu.ac.jp'

  def self.get_testcase_in(problem_id, serial)
    uri = URI.parse(@endpoint + "/testcases/#{problem_id}/#{serial}/in")
    res = Net::HTTP.get_response(uri)
    res.body
  end

  def self.get_testcase_out(problem_id, serial)
    uri = URI.parse(@endpoint + "/testcases/#{problem_id}/#{serial}/out")
    res = Net::HTTP.get_response(uri)
    res.body
  end

  def self.get_header(problem_id)
    uri = URI.parse(@endpoint + "/testcases/#{problem_id}/header")
    res = Net::HTTP.get_response(uri)
    JSON.parse(res.body)
  end
end
